#!/usr/bin/env bash
# run_scalar_tests.sh — quick test runner for CPP06 ScalarConverter
# Usage:
#   1) Put this script next to your built ./converter binary (or pass --build)
#   2) Run: bash run_scalar_tests.sh [--build]
#      --build : compile all *.cpp into ./converter with C++98 flags
#
# Notes:
# - Tests check for required substrings/regex in output (order-insensitive per line).
# - Add your own cases at the bottom following the examples.

set -u

BOLD='' ; NORM='' ; GREEN='' ; RED='' ; YELLOW=''
if [ -t 1 ]; then
  BOLD="$(printf '\033[1m')" ; NORM="$(printf '\033[0m')"
  GREEN="$(printf '\033[32m')" ; RED="$(printf '\033[31m')" ; YELLOW="$(printf '\033[33m')"
fi

BUILD=0
if [ "${1-}" = "--build" ]; then BUILD=1; fi

if [ $BUILD -eq 1 ]; then
  echo "${BOLD}== Building ./converter (C++98)…${NORM}"
  if command -v g++ >/dev/null 2>&1; then CXX=g++; elif command -v clang++ >/dev/null 2>&1; then CXX=clang++; else
    echo "${RED}No C++ compiler found (g++/clang++).${NORM}"; exit 1
  fi
  # Compile all .cpp in current dir; adjust if your files are elsewhere.
  $CXX -std=c++98 -Wall -Wextra -Werror -O2 *.cpp -o converter || { echo "${RED}Build failed.${NORM}"; exit 1; }
fi

if [ ! -x ./converter ]; then
  echo "${RED}Missing ./converter binary. Build it or run with --build.${NORM}"
  exit 1
fi

pass=0; fail=0

# run one test: args: "input"   "pattern1;;pattern2;;..."
run_test () {
  local input="$1"; shift
  local patterns="$1"
  local out
  out="$(./converter "$input" 2>&1)"
  local ok=1

  IFS=';;' read -r -a pats <<< "$patterns"

  for p in "${pats[@]}"; do
    if ! printf '%s\n' "$out" | grep -E -q -- "$p"; then
      ok=0
      break
    fi
  done

  echo "----"
  echo "${BOLD}Input:${NORM} $input"
  echo "${BOLD}Output:${NORM}"
  printf '%s\n' "$out"
  if [ $ok -eq 1 ]; then
    echo "${GREEN}PASS${NORM}"
    pass=$((pass+1))
  else
    echo "${RED}FAIL${NORM}  (missing pattern: ${YELLOW}$p${NORM})"
    fail=$((fail+1))
  fi
}

echo "${BOLD}== Running tests ==${NORM}"

# ---------- Core tests ----------

# Simple int-ish double
run_test "42" \
"^char: '.*'$;;^int: 42$;;^float: 42(\.0)?f$;;^double: 42(\.0)?$"

# Printable char
run_test "a" \
"^char: a$;;^int: 97$;;^float: 97(\.0)?f$;;^double: 97(\.0)?$"

# Non-displayable char via numeric
run_test "7" \
"^char: Non displayable$;;^int: 7$"

# Float literal fixed formatting
run_test "900.0f" \
"^char: (Non displayable|impossible)$;;^int: 900$;;^float: 900\.0f$;;^double: 900\.0$"

# Float literal scientific formatting
run_test "900000000000.0f" \
"^char: impossible$;;^int: impossible$;;^float: 9e\+11f$;;^double: 9e\+11$"

# Double literal scientific formatting
run_test "900000000000.0" \
"^char: impossible$;;^int: impossible$;;^float: 9e\+11f|float: inff$;;^double: 9e\+11$"

# Float overflow to +inff
run_test "1e39f" \
"^char: impossible$;;^int: impossible$;;^float: inff$;;^double: 1e\+39$"

# Float overflow to -inff
run_test "-1e39f" \
"^char: impossible$;;^int: impossible$;;^float: -inff$;;^double: -1e\+39$"

# Double overflow to +inf (very big number)
run_test "1e309" \
"^char: impossible$;;^int: impossible$;;^float: inff$;;^double: inf$"

# Double overflow to -inf
run_test "-1e309" \
"^char: impossible$;;^int: impossible$;;^float: -inff$;;^double: -inf$"

# Pseudoliterals
run_test "nan"  "^char: impossible$;;^int: impossible$;;^float: nanf$;;^double: nan$"
run_test "nanf" "^char: impossible$;;^int: impossible$;;^float: nanf$;;^double: nan$"
run_test "inf"  "^char: impossible$;;^int: impossible$;;^float: inff$;;^double: inf$"
run_test "-inf" "^char: impossible$;;^int: impossible$;;^float: -inff$;;^double: -inf$"
run_test "+inf" "^char: impossible$;;^int: impossible$;;^float: inff$;;^double: inf$"

# Integer extremes into float/int
run_test "2147483647"  "^int: 2147483647$"
run_test "-2147483648" "^-?char: (Non displayable|impossible)$;;^int: -2147483648$"

# Precision edge for double (17 digits → rounding expected)
run_test "99999999999999999" "^double: 1e\+17|^double: 99999999999999992\.0|^double: 100000000000000000\.0$"

# Bad literal
run_test "hello" "^Literal could not be converted$"

echo "----"
echo "${BOLD}Summary:${NORM} ${GREEN}${pass} passed${NORM}, ${RED}${fail} failed${NORM}"
[ $fail -eq 0 ]

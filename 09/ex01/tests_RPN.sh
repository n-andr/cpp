#!/bin/bash

# Path to your program
PROG=./RPN

# Pretty colors
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"

test_case() {
    INPUT="$1"
    EXPECTED="$2"

    echo "----------------------------------------"
    echo "Test:      $PROG \"$INPUT\""
    echo "Expected:  $EXPECTED"

    RECEIVED=$($PROG "$INPUT" 2>&1)
    echo "Received:  $RECEIVED"

    if [ "$RECEIVED" = "$EXPECTED" ]; then
        echo -e "${GREEN}OK${RESET}"
    else
        echo -e "${RED}KO${RESET}"
    fi
    echo
}

# --- Valid arithmetic ---
test_case "1 2 +" "3"
test_case "9 9 +" "18"
test_case "9 2 -" "7"
test_case "2 9 -" "-7"
test_case "6 7 *" "42"
test_case "9 3 /" "3"
test_case "9 2 /" "4.5"   # float output (your version)
test_case "3 4 + 5 *" "35"
test_case "5 1 2 + 4 * + 3 -" "14"  # classic RPN example

# --- Multiple operators ---
test_case "5 5 5 + +" "15"
test_case "5 1 2 + +" "8"
test_case "9 3 / 2 /" "1.5"

# --- Spaces abuse ---
test_case "   3   4   +" "7"
test_case "8     2   /" "4"
test_case "     5 2 /    " "2.5"

# --- Error: invalid characters ---
test_case "1 2 a +" "Error: invalid character in input"
test_case "! 2 +" "Error: invalid character in input"
test_case "3 4 + ?" "Error: invalid character in input"

# --- Error: too many operands ---
test_case "1 2 3 +" "Error: too many operands"
test_case "4 5 +" "9"   # correct first
test_case "4 5 + 6" "Error: too many operands"

# --- Error: not enough operands ---
test_case "+" "Error: not enough operands"
test_case "1 +" "Error: not enough operands"
test_case "1 2 +" "3"   # normal
test_case "1 2 + +" "Error: not enough operands"

# --- Division by zero ---
test_case "4 0 /" "Error: Division by 0"
test_case "9 0 /" "Error: Division by 0"

# --- Weird spacing and input formatting ---
test_case "1    2    +" "3"
test_case "7      2   /" "3.5"
test_case "     9     3    *   " "27"

# --- Trailing operators (should error) ---
test_case "1 2 + +" "Error: not enough operands"
test_case "5 +" "Error: not enough operands"

# --- Leading operators (should error immediately) ---
test_case "+ 1 2" "Error: not enough operands"
test_case "- 2 3" "Error: not enough operands"

# --- Empty tokens ---
test_case "" "Error: empty input"

# --- Mixed valid & invalid ---
test_case "2 3 + x" "Error: invalid character in input"
test_case "9 4 * z" "Error: invalid character in input"


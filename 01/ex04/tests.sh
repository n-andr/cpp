#!/bin/sh

#-----------------------------------
# How to run:
# Give the script execute permission
# bash chmod +x tests.sh
#
# Run it
# bash ./tests.sh
#-----------------------------------


cmd='./sed_is_for_losers'

PURPLE='\033[0;35m'
BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m' 

echo "hello world lol lol lol" > 42.42

echo -e "\n${PURPLE}Too many arguments: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 2 3 4${RESET}"
echo -e "Output: $(${cmd} 42.42 2 3 4)"
grep "xxx" 42.42.replace
if [ $? -eq 2 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

echo -e "${PURPLE}File does not exist: ${RESET}"
echo -e "${BLUE}${cmd} ranDoMname 2 3${RESET}"
echo -e "Output: $(${cmd} ranDoMname 2 3)"
grep "xxx" ranDoMname.replace
if [ $? -eq 2 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi
echo -e "${PURPLE}No matches found: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 xxx zzz${RESET}"
echo -e "Output: $(${cmd} 42.42 xxx zzz)"
grep "xxx" 42.42.replace
if [ $? -eq 1 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

echo -e "${PURPLE}Replace 1 character: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 h 0${RESET}"
echo -e "Output: $(${cmd} 42.42 h 0)"
grep "h" 42.42.replace
if [ $? -eq 1 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

echo -e "${PURPLE}Replace a string: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 hello hi${RESET}"
echo -e "Output: $(${cmd} 42.42 hello hi)"
grep "hello" 42.42.replace
if [ $? -eq 1 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

echo -e "${PURPLE}Replace a string that repeats: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 lol HAHA${RESET}"
echo -e "Output: $(${cmd} 42.42 lol HAHA)"
grep "lol" 42.42.replace
if [ $? -eq 1 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

cat 42.42
cat 42.42.replace
rm -rf 42.42
rm -rf 42.42.replace
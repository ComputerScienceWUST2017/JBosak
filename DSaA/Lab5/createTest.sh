#!/usr/bin/env bash
g++ createTest.cpp -Wall -Wextra -o createTest.out
output=$(./createTest.out)
if [ -d tests ]; then
  if [ ! -e "tests/inputs" ]; then
    mkdir tests/inputs
  fi
  if [ ! -e tests/answers ]; then
    mkdir tests/answers
  fi
else
  mkdir tests
  mkdir tests/inputs
  mkdir tests/answers
fi
if [ ! $# -eq 0 ]; then
  g++ $1 -Wall -Wextra -o a.out
fi
for i in `seq 1 $2`;
do
  ./createTest.out > tests/inputs/i$i.txt
  if [ -x "a.out" ]; then
    ./a.out < tests/inputs/i$i.txt > tests/answers/o$i.txt
  fi
done
rm createTest.out

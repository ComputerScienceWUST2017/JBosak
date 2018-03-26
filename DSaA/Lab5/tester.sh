#!/usr/bin/env bash
if [ $# -eq 0 ]; then
  echo "------No .cpp files supplied"
else
  echo "------COMPILING FILE $1"
  g++ $1 -Wall -Wextra -o a.out
fi
if [ -e "a.out" ]; then
  if [ ! -e tests/myOutput ]; then
    mkdir tests/myOutput
  else
    rm tests/myOutput/*.txt
  fi
  for i in `seq 1 $2`;
  do
    if [ -e "tests/inputs/i$i.txt" ] && [ -e "tests/answers/o$i.txt" ]; then
      echo "------TEST $i"
      output=$(./a.out < tests/inputs/i$i.txt | tee tests/myOutput/my$i.txt)
      answer=$(cat tests/answers/o$i.txt)
      if [ "$output" == "$answer" ]; then
        echo "------CORRECT"
      else
     	  #meld tests/myOutput/my$i.txt tests/answers/o$i.txt
        echo "------SOMETHING IS WRONG!"
        echo "------Your output is:"
        echo "$output"
        echo "------Instead of that should be:"
        echo "$answer"
      fi
    else
        echo "------Files not found!"
    fi

  done
  rm a.out
fi

#!/bin/bash

set -e

day="01"
if [[ "$1" != "" ]]; then
    day=$1
fi

echo "Building..."
gcc -Include -Wall -Wextra -c src/problem_$day.c -o src/problem.o

set +e

echo "Testing..."
gcc -Iinclude test/test_problem_$day.c src/problem.o -o test/test_problem
./test/test_problem

echo "Cleaning up..."
rm -f src/*.o test/test_problem
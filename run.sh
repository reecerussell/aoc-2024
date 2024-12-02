#!/bin/bash

set -e

# Set the day (problem number) to build
day="01"
if [[ "$1" != "" ]]; then
    day=$1
fi

output_dir="bin"
mkdir -p "$output_dir"

# Set the include directory
include_dir="include"

# Get all .c files in the src directory
src_files=$(find src -type f -name "*.c")

# Compile all source files to object files
for file in $src_files; do
    gcc -c "$file" -I"$include_dir" -o "$output_dir/$(basename ${file%.c}.o)"
done

gcc -c "test/test_problem_$day.c" -I"$include_dir" -o "bin/test_problem_$day.o"

# Link all object files together into a single executable
gcc $output_dir/*.o -o "$output_dir/program"

set +e

echo "Running..."
./"$output_dir/program"

# Clean up
echo "Cleaning up..."
# rm -rf bin

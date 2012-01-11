#!/bin/bash

echo "Compile q-file1.c's main..."
gcc -D__main=1 q-file1.c q-file2.c q-file3.c
./a.out

echo "Compile q-file2.c's main..."
gcc -D__main=2 q-file1.c q-file2.c q-file3.c
./a.out

echo "Compile q-file3.c's main..."
gcc -D__main=3 q-file1.c q-file2.c q-file3.c
./a.out


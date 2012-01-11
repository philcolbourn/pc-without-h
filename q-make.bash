#!/bin/bash

#
#    Copyright 1991, 2012 Phil Colbourn
#
#    This file is part of pc-without-h.
#
#
#    pc-without-h is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    pc-without-h is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with pc-without-h.  If not, see <http://www.gnu.org/licenses/>.
#

echo "Compile q-file1.c's main..."
gcc -D__main=1 q-file1.c q-file2.c q-file3.c
./a.out
echo "Output should be"
echo "f1: main"
echo "f2: main"
echo "f3: main"

echo "Compile q-file2.c's main..."
gcc -D__main=2 q-file1.c q-file2.c q-file3.c
./a.out
echo "Output should be"
echo "f1: not main"
echo "f2: not main"
echo "f3: not main"

echo "Compile q-file3.c's main..."
gcc -D__main=3 q-file1.c q-file2.c q-file3.c
./a.out
echo "Output should be"
echo "f1: 3rd"
echo "f2: 3rd"
echo "f3: 3rd"


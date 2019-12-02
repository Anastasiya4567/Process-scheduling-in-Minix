#!/bin/sh
cc test.c -o test

echo "Testing"
./test $1 $2 &
./test $3 $4 &
./test $5 $6 &

#! /bin/bash

rm -rf *.o

if [[ ! -d bin ]]; then
mkdir bin

fi
gcc -c linkedlist.c test/test_linkedlist.c
gcc -o bin/out *.o
rm -rf *.o
./bin/out
rm -rf bin
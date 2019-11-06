#!/bin/bash

rm *.o
gcc -c main.c reverse.c length.c
ar cr libtest.a reverse.o length.o

gcc -o myprog main.o -ltest -L .
./myprog

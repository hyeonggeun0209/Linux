#!/bin/bash


a=`expr $1 / 100`
b=`expr '(' $1 - $a '*' 100 ')' / 10`
c=`expr $1 - $a '*' 100 - $b '*' 10`

d=`expr $a + $b + $c`
echo $d
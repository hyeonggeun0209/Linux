#!/bin/bash

echo "type (0-100): "
read num

if [ $num -lt 0 -o $num -gt 100 ]
then
	echo wrong number
elif [ $num -le 50 ]
then
	echo "less than or equal to 50"
else
	echo "greater than 50"
fi

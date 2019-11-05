#!/bin/bash

funcf() {
	for (( i=1;i<=$1;i++ ))
	do
		if (( $1 % i == 0 ))
		then
			echo "$i"
		fi
	done
}
funcp() {
	for (( i=2;i<=$1;i++ ))
	do
		num=0
		for (( j=1;j<=i;j++ ))	
		do
			if (( i % j == 0 ))
			then
				num=`expr $num + 1`
			fi
		done
		
		if (( $num == 2 ))
		then
			echo "$i"
		fi
	done
}
while true
do
	read input1 input2
	if [ $input1 == q -o $input1 == Q ]
	then
		break
	fi
	
	if [ $input2 == f ]
	then
		funcf $input1 $input2
	elif [ $input2 == p ]
	then
		funcp $input1 $input2
	else
		echo "error!"; continue

	fi
done
























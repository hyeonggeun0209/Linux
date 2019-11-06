#!/bin/bash

func() {
	for (( i=1;i<=$input;i++ ))
	do
		if (( $input % i == 0 ))
		then
			echo "$i"
		fi
	done
}
func1() {
	num=0
	for (( j=1;j<=$i;j++ ))
	do
		if (( $i % j == 0 ))
		then
			num=`expr $num + 1`
		fi
	done
	return $num
}
while true
do
	echo "input number "
	read input
	if [ $input == q -o $input == Q ]
	then
		break
	fi

	if (( input % 2 == 1))
	then
		echo "odd!"
	elif (( input % 2 == 0 ))
	then
		echo "even!"
	fi
	

	for (( i=2;i<=$input;i++ ))
	do
		func1 $i
		prime=$?
		if (( $prime == 2 ))
		then
			echo "$i"
		fi
	done	

done
echo "finish"

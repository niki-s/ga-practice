#! /bin/bash

##NOTE: edit "first-deJong" file to change meta variables like Px and Pm

echo "running first DeJong test function 30 times..."

MAXRUNS=30
count=1
outfile="outfile1-"

while [[ "$count" -le $MAXRUNS ]]
do
	number=$RANDOM
	let "number %= 200"
	./ga first-deJong $outfile$number $number
	#echo "./ga first-deJong $outfile$number $number"
	let "count += 1"
done
#./ga first-deJong outfile_177 177


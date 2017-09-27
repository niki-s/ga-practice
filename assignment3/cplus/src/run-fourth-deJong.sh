#! /bin/bash

echo "running fourth DeJong test function 30 times..."

MAXRUNS=30
count=1
outfile="outfile4-"

while [[ "$count" -le $MAXRUNS ]]
do
	number=$RANDOM
	let "number %= 200"
	./ga fourth-deJong $outfile$number $number
	#echo "./ga first-deJong $outfile$number $number"
	let "count += 1"
done
#./ga first-deJong outfile_177 177


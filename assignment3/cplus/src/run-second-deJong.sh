#! /bin/bash

echo "running second DeJong test function 30 times..."

MAXRUNS=30
count=1
outfile="outfile2-"

while [[ "$count" -le $MAXRUNS ]]
do
	number=$RANDOM
	let "number %= 200"
	./ga second-deJong $outfile$number $number
	#echo "./ga first-deJong $outfile$number $number"
	let "count += 1"
done
#./ga first-deJong outfile_177 177


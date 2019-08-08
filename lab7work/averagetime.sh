#!/bin/bash
#getting the dictionary file
echo "enter the exponent for counter.cpp::"
read INPUT
TIME=0
TEMP=0
IT=5
#running five times
if [[INPUT!="quit"]] ; then
    while [ $IT -lt 1] ; do
	let IT+=1
	let TEMP=`/a.out $INPUT | tail -1`
	echo "Running iteration ${IT}..."
	echo "time taken: ${TEMP} ms"
	let TIME+=TEMP
    done
done
#getting the average value
AVERAGE=$(($TIME / 5))
#printing the result
echo "Average runtime was ${AVERAGE} ms"

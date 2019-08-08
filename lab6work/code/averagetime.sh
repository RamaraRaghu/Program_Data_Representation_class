#!/bin/bash
#getting the dictionary file
echo "Please enter the dictionary file name:"
read Dict
echo "Please enter the grid file name:"
read Grid
#getting run time variables that store each test
RUN_ONE=`./a.out $Dict $Grid | tail -1`
RUN_TWO=`./a.out $Dict $Grid | tail -1`
RUN_THREE=`./a.out $Dict $Grid | tail -1`
RUN_FOUR=`./a.out $Dict $Grid | tail -1`
RUN_FIVE=`./a.out $Dict $Grid | tail -1`
#getting the average value
AVERAGE=$((1000($RUN_ONE+$RUN_TWO+$RUN_THREE+$RUN_FOUR+$RUN_FIVE)/5))
#printing the result
echo "Average runtime is: $AVERAGE"

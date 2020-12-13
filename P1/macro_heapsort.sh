#!/bin/bash

echo "" >> heapsort.dat
NUM=1000

while [ $NUM -le 100000 ]; do
    ./heapsort $NUM >> heapsort.dat
    let NUM=$NUM+1000
done

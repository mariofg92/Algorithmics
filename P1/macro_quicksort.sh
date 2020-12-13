#!/bin/bash

echo "" >> quicksort.dat
NUM=1000

while [ $NUM -le 100000 ]; do
    ./quicksort $NUM >> quicksort.dat
    let NUM=$NUM+1000
done

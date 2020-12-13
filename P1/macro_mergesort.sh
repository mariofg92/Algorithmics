#!/bin/bash

echo "" >> mergesort.dat
NUM=1000

while [ $NUM -le 100000 ]; do
    ./mergesort $NUM >> mergesort.dat
    let NUM=$NUM+1000
done

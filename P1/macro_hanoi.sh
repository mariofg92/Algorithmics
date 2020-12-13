#!/bin/bash

echo "" >> hanoi.dat
NUM=10

while [ $NUM -le 35 ]; do
    ./hanoi $NUM >> hanoi.dat
    let NUM=$NUM+1
done

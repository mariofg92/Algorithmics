#!/bin/bash

echo "" >> burbuja3.dat
NUM=1000

while [ $NUM -le 100000 ]; do
    ./burbuja $NUM >> burbuja3.dat
    let NUM=$NUM+1000
done
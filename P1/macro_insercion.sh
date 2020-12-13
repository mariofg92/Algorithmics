#!/bin/bash

echo "" >>  insercion.dat
NUM=1000

while [ $NUM -le 100000 ]; do
    ./insercion $NUM >> insercion.dat
    let NUM=$NUM+1000
done

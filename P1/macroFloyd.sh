#!/bin/bash

echo "" >> floyd.dat
NUM=50

while [ $NUM -le 2000 ]; do
    ./floyd $NUM >> floyd.dat
    let NUM=$NUM+50
done
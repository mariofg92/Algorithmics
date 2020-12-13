#!/bin/bash

echo "" >> mezclaVectoresDyV.dat
NUM=100

while [ $NUM -le 50000 ]; 
	do
    ./MezclaOrdenadoDyV $NUM 20 >> mezclaVectoresDyV.dat
    let NUM=$NUM+100
done
#!/bin/bash

echo "" >> mezclaComparar.dat
NUM=100

while [ $NUM -le 25000 ]; 
	do
    ./MezclaOrdenado $NUM 20 >> mezclaComparar.dat
    let NUM=$NUM+100
done

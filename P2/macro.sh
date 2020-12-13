#!/bin/bash

echo "" >> mezclaVectores.dat
NUM=100

while [ $NUM -le 10000 ]; 
	do
    ./MezclaOrdenado $NUM 20 >> mezclaVectores.dat
    let NUM=$NUM+100
done
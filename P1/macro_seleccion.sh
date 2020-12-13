#!/bin/bash

echo "" >> seleccion.dat
NUM=1000

while [ $NUM -le 100000 ]; do
    ./seleccion $NUM >> seleccion.dat
    let NUM=$NUM+1000
done

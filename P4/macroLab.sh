#!/bin/bash

echo "" >> laberinto.dat
I=4
J=1
MEDIA=0
N=0
 
while [ $I -le 20 ]; 
do
	./lab2 $I>>laberinto.dat
    	let I=$I+1
done

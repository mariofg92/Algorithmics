#!/bin/bash
g++ -std=gnu++11 vBB.cpp -o vBB #compilacion

I=5
while [ $I -le 15 ];
do
./vBB $I >> tiempo.dat #Aqui se cambia el num de ciudades (ahora 10 ciudades)
let I=$I+1
done

#saca las graficas de greedy y branch... para comparar
echo "set terminal png; set ylabel 'y'; set xlabel 'x';set output './solucion.png'; \
plot 'solucion.dat' using 2:3 with points  lc rgb 'red' lw 5 pt 5 ps 0.1, \
'solucion.dat' using 2:3 with lines lc rgb 'green' lw 1"|gnuplot

echo "set terminal png; set ylabel 'tiempo'; set xlabel 'tamanio';set output './tiempo.png'; \
plot 'tiempo.dat' with lines"|gnuplot

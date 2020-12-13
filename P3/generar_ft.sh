#!/bin/csh -f
set i = 10000
echo -n > viajante_BK_ft.dat
while ($i < 60000)
    echo -n "$i  " >> viajante_BK_ft.dat
    ./viajante_BK $i 0 1 >> viajante_BK_ft.dat
    @ i += 2500
end

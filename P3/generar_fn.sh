#!/bin/csh -f
set i = 10000
echo -n > viajante_BK_fN.dat
while ($i < 60000)
    echo -n "$i  " >> viajante_BK_fN.dat
    ./viajante_BK $i 0 1 >> viajante_BK_fN.dat
    @ i += 2500
end

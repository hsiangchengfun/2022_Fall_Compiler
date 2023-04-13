#!/bin/bash

RED='\033[0;31m'
LGR='\033[1;32m'
YEL='\033[1;33m'
NC='\033[0m'

dir1="./*.p"
dir2="answers"
dir3="guiles"
dir4="input"

mkdir -p guiles
mkdir -p answers

echo " ======== gen answers ========= "

for file in ${dir1};
do
    prefile="${file%.p}"
    inp="${dir4}/${prefile#*/}.input"
    ans="${dir2}/${prefile#*/}.ans"


    echo "Generate ${dir3}/${prefile#*/}.guile"
    ../scmtrans ${file} > ${dir3}/${prefile#*/}.guile

    echo "Generate answers for ${file}"
    if [ -f ${inp} ];then
      cat ${inp} | guile ${dir3}/${prefile#*/}.guile 1> ${ans} 2>/dev/null
    else
      guile ${dir3}/${prefile#*/}.guile 1> ${ans} 2>/dev/null
    fi
done


echo " ========================== "

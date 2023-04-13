#!/bin/bash

RED='\033[0;31m'
LGR='\033[1;32m'
YEL='\033[1;33m'
NC='\033[0m'

dir1="assembly/*"
dir2="answers"
dir3="input"
dir4="output"

if [ ! -d "assembly" ]
then
    echo "[error] should genreate the assembly/ dir first"
    exit 1
fi

if diff --help 2>&1 | grep "strip-trailing" > /dev/null 2>&1
then
    DIFF="diff -s --strip-trailing-cr"
else
    DIFF="diff -s"
fi

correct=0
pass=0
ignore=0

echo " ======== testing ========= "

mkdir -p ${dir4}

for file in ${dir1};
do
    prefile="${file%.j}"
    inp="${dir3}/${prefile#*/}.input"
    ans="${dir2}/${prefile#*/}.ans"
    out="${dir4}/${prefile#*/}.output"
    name="${prefile#*/}"

    if [ ! -f ${inp} ]
    then
        cd class
        timeout 3s java ${name} 1> ../${out} 2>/dev/null
        cd ..
    else
        cd class
        timeout 3s cat ../${inp} | java ${name} 1> ../${out} 2>/dev/null
        cd ..
    fi



    # check the answers/ exist
    if [ ! -f ${ans} ]
    then
        ((ignore=ignore+1))
        echo -e "${YEL}[-] The answer of ${file} didn't exist${NC}"
        continue
    fi

    ((pass=pass+1))

    # compare the file with answer in answers/
    #if cmp -s "${file}" "${ans}"
    if $DIFF "${out}" "${ans}" > /dev/null
    then
        ((correct=correct+1))
        echo -e "$(printf "%02d" $pass). ${LGR}[O] ${file} pass the test${NC}"
    else
        echo -e "$(printf "%02d" $pass). ${RED}[X] ${file} is incorrect${NC}"
    fi
done


echo " ========================== "

echo " passed the test ${correct}/${pass}, and ${ignore} ignored"

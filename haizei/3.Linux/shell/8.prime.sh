#!/bin/bash
if [[ $# -ne 2 ]]; then
    echo "Error"
    exit
fi

Start=$1
End=$2

declare -a Prime

function init_prime() {
    local end=$1
    local i
    for((i=2; i<=${end}; i++));do
        for((j=$[${i} * ${i}]; j<=${end}; j+=i));do
            Prime[${j}]=1
        done
    done
}

init_prime ${End}

for((i=${Start}; i<=${End}; i++));do
    if [[ ${Prime[i]}x == x ]];then
        echo $i
    fi
done




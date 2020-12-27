#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "Error"
    exit
fi

Start=$1
End=$2

function is_prime() {
    num=$1
    local i
    for ((i=2; i<$num; i++));do
        if [[ $[${num}%${i}] -eq 0 ]];then
            return 1
        fi
    done
    return 0
}   


for ((i=$Start; i<=$End; i++));do
    is_prime $i
    if [[ $? -eq 0 ]];then
        sum=$[$sum + $i]
    fi
done

echo $sum


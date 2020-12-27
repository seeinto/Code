#!/bin/bash

read a

declare -a prime

cnt=1
for (( i=2;i<=10000;i++ ));do
        if [[ ${prime[${i}]}x == x ]];then
            prime[${cnt}]=${i}
            cnt=$[ ${cnt}+1 ]
        fi
    for (( j=$[ ${i} * ${i} ];j<=10000;j+=${i} ));do
        prime[${j}]=1
    done
done

echo ${prime[${a}]}

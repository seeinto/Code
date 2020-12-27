#!/bin/bash


declare -a num
read a b

for (( i=1;i<=${b};i++ ));do
    read c d
    for (( j=${c};j<=${d};j++ ));do
        num[${j}]=1
    done
done

for (( j=0;j<=${a};j++ ));do
    if [[ ${num[${j}]}x == x ]];then
        sum=$[ ${sum}+1 ]
    fi
done

echo $sum

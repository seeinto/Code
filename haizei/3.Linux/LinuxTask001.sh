#!/bin/bash

a=`last | grep wxx | grep -v "wtmp begins" | grep -v "^$" | cut -d ' ' -f 1 | sort  |uniq -c |sort -r |head -n1 | cut -c 6-7`
echo -e "\033[1;32m最近登录的次数为 : $a\033[0m"

b=`last | head -n 2 | tail -n 1  | cut -d " " -f 19-30 `
echo -e "\033[1;32m上次登录的时间为 : $b\033[0m"

c=`date +"%Y-%m-%d  %H:%M:%S"`
echo -e "\033[1;32m这次登录的时间为 : $c\033[0m"

echo " "

echo -e "\033[1;35m名人名言 : 今天应做的事没有做，明天再早也是耽误了。——裴斯泰洛齐 \033[0m"

echo " "

curl wttr.in/guangzhou -s  | head -n 7 

echo " "

curl wttr.in/guangzhou -s  | tail -n 3 |head -n 1

echo " "

echo -e "\033[1;33m暖心问候 : 让思念凝成一朵云，为你遮住骄阳；让关心化成一阵风，为你吹散烦恼；让祝福汇成一首诗，为你轻轻吟唱。 \033[0m"

#!/bin/bash

echo "calc_score"

g++ -std=gnu++17 -Wall -Wextra -O2 main.cpp -D SCORE -o main.out

score=0

for i in {0..99}; do
    echo -n "No.${i} : "
    num=$(printf "%04d\n" "${i}")
    D=$(head -n 1 "inputs/${num}.txt" | tr '\r\n' ' ')

    st=$(date +'%s.%3N')

    tmp=$(./main.out < "inputs/${num}.txt")

    et=$(date +'%s.%3N')
    rt=$(echo "scale=3; $et - $st" | bc)

    echo -n $tmp " ("
    echo $rt"s)"
    score=$(($score + $tmp))
done

echo "Total:" $score
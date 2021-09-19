#!/bin/bash
t=0 
while true; do
    let "t=$t + 1" echox
    printf $t                        
    printf ": "
    ./generator > intxt              
    ./p1 < intxt    > yoursort       
    ./std < intxt    > stdsort       
    
    if diff yoursort stdsort  > diffsort; then
        printf "Accepted sort\n"
    else
        printf "Wrong sort\n"
        break
    fi       


    sleep 0.2s
done

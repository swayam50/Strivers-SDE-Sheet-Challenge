#include <bits/stdc++.h> 

void sort012(int *arr, int n)
{
    int zerPos = 0;
    while(zerPos < n && arr[zerPos] == 0)
        zerPos++;
    if(zerPos == n)    return;
    
    int onePos = zerPos;
    
    int twoPos = n - 1;
    while(twoPos >= 0 && arr[twoPos] == 2)
        twoPos--;
    if(twoPos == -1)    return;
    
    while(onePos <= twoPos)
    {
        if(arr[onePos] == 0)
            swap(arr[zerPos++], arr[onePos++]);
        else if(arr[onePos] == 1)
            onePos++;
        else if(arr[onePos] == 2)
            swap(arr[onePos], arr[twoPos--]);
    }
}
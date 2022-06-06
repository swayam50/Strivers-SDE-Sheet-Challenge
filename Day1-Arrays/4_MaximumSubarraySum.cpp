#include <bits/stdc++.h> 

long long maxSubarraySum(int arr[], int n)
{ 
    long long currSum = 0L, maxSum = 0L;
    for(int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if(currSum < 0)
            currSum = 0;
        
        maxSum = max(currSum, maxSum);
    }
    
    return maxSum;     
}
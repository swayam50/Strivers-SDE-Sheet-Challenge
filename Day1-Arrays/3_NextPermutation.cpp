#include <bits/stdc++.h> 

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int i = n-2;
    while(i >= 0 && permutation[i] < permutation[i+1])
        i--;
    
    if(i == -1)
    {
        sort(permutation.begin(), permutation.end());
        return permutation;
    }
    
    int j = n-1;
    while(j > i && permutation[i] > permutation[j])
        j--;
    
    swap(permutation[i], permutation[j]);
    reverse(permutation.begin() + i + 1, permutation.end());
    
    return permutation;
}
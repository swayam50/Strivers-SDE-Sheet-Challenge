#include <bits/stdc++.h> 

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long>> pascal(n, vector<long long>(0));
    for(int i=1; i<=n; i++)
    {
        pascal[i-1] = vector<long long>(i, 1L);
        for(int j=1; j<i-1; j++)
            pascal[i-1][j] = pascal[i-2][j-1] + pascal[i-2][j];
    }
        
    return pascal;
}
#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices){
    
    int maxProfit = 0, minPrice = INT_MAX;
    for(int &p : prices)
    {
        minPrice = min(minPrice, p);
        maxProfit = max(maxProfit, p - minPrice);
    }
    
    return maxProfit;
}
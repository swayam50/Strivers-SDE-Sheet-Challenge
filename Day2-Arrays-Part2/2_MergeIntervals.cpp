#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> merged;
    for(vector<int> &interval : intervals)
    {
        if(merged.empty() || interval[0] > merged.back()[1])
            merged.emplace_back(interval);
        else
            merged[merged.size()-1][1] = max(interval[1], merged.back()[1]);
    }
    
    return merged;
}
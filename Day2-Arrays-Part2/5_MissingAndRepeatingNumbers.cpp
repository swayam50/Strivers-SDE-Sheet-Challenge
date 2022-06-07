#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int actualXOR = 1, nonrepeatsXOR = arr[0];
    for(int i=1; i<n; i++)
    {
        actualXOR ^= (i + 1);
        nonrepeatsXOR ^= arr[i];
    }
    
    int repeat_missing_XOR = actualXOR ^ nonrepeatsXOR;
    int set_bit_mask = ~(repeat_missing_XOR - 1) & repeat_missing_XOR;
    
    int set1 = 0, set2 = 0;
    for(int i=0; i<n; i++)
    {      
        if(set_bit_mask & arr[i])
            set1 ^= arr[i];
        else
            set2 ^= arr[i];
        
        if(set_bit_mask & (i + 1))
            set1 ^= (i + 1);
        else
            set2 ^= (i + 1);
    }
    
    int r, m;
    for(int i=0; i<n; i++)
    {
        if(!(set1 ^ arr[i]))
        {
            r = set1;
            m = set2;
            break;
        }
        else if(!(set2 ^ arr[i]))
        {
            r = set2;
            m = set1;
            break;
        }
    }
    
    return make_pair(m, r);
    
}

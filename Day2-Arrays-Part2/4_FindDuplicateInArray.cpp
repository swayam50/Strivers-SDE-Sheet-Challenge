#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
	int pos = 0;
    while(arr[pos] != pos && arr[pos] != -1)
    {
        int next = arr[pos];
        arr[pos] = -1;
        pos = next;
    }
    
    return pos;
}
import java.util.* ;
import java.io.*; 

class Solution {
    
    public static long getInversions(long arr[], int n) {
        int low = 0, high = n-1;
        long inverts = divide(arr, low, high);
        return inverts;
    }
    
    private static long divide(long[] arr, int low, int high) {
        if(low >= high)    return 0L;
        
        int mid = low + (high - low) / 2;
        long leftInvertions = divide(arr, low, mid);
        long rightInvertions = divide(arr, mid+1, high);
        
        return merge(arr, low, mid, high) + leftInvertions + rightInvertions;
    }
    
    private static long merge(long[] arr, int low, int mid, int high) {
        
        long[] temp = new long[high-low+1];
        
        long count = 0L;
        int i = low, j = mid + 1, k = 0;
        while(i <= mid && j <= high) {
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else {
                count += (long)mid - (long)i + 1L;
                temp[k++] = arr[j++];
            }
        }
        while(i <= mid)
            temp[k++] = arr[i++];
        while(j <= high)
            temp[k++] = arr[j++];
        
        for(int x=low, y=0; y < temp.length; x++, y++)
            arr[x] = temp[y];
        
        return count;
    }
}
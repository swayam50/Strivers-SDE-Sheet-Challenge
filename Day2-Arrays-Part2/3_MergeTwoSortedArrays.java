class Solution {
    
    public static int[] ninjaAndSortedArrays(int arr1[], int arr2[], int m, int n) {
        
        int k = arr1.length - 1, i = m - 1, j = n - 1;
        
        while(i >= 0 && j >= 0) {
            if(arr1[i] > arr2[j])
                arr1[k--] = arr1[i--];
            else
                arr1[k--] = arr2[j--];
        }
        while(i >= 0)
            arr1[k--] = arr1[i--];
        while(j >= 0)
            arr1[k--] = arr2[j--];
        
        return arr1;
    }
}

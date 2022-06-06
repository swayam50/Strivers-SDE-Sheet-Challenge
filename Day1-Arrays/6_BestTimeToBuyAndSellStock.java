import java.util.ArrayList;

class Solution{

    public static int maximumProfit(ArrayList<Integer> prices){
        
        int maxProfit = 0, minVal = Integer.MAX_VALUE;
        
        for(int p : prices)
        {
            minVal = Math.min(minVal, p);
            maxProfit = Math.max(maxProfit, p - minVal);
        }
        
        return maxProfit;
    }

}

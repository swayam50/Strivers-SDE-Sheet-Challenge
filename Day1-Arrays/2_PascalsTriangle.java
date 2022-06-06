import java.util.ArrayList;

class Solution {

	public static ArrayList<ArrayList<Long>> printPascal(int n) {

    	ArrayList<ArrayList<Long>> pascal = new ArrayList<>(n);
        
        for(int i=0; i<n; i++) {
        	
            pascal.add(new ArrayList<Long>(i+1));
        	
            for(int j=0; j<i+1; j++) {
        		if(j == 0 || j == i)
        			pascal.get(i).add(1L);
        		else
        			pascal.get(i).add(pascal.get(i-1).get(j) + pascal.get(i-1).get(j-1));
        	}
        }

        return pascal;

	}
}
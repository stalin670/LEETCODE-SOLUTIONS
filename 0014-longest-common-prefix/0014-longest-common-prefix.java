class Solution {
    public String longestCommonPrefix(String[] arr) {
        int n=arr.length;
        String ans="";
        int minLen=200;
        for(int i=0;i<n;i++){
            int x=arr[i].length();
            minLen=Math.min(minLen,x);
        }
        
        for(int i=0;i<minLen;i++){
            for(int j=0;j<n-1;j++){
                int currChar=arr[j].charAt(i);
                int nextChar=arr[j+1].charAt(i);
                if(currChar!=nextChar){
                    return ans;
                }
            }
            ans+=arr[0].charAt(i);
        }
        return ans;
    }
}
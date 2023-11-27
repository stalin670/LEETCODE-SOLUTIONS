class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=size(height)-1;
        int ans=0;
        while(left<right){
            if(height[left]>height[right]){
                int area=(right-left)*height[right];
                ans=max(ans,area);
                right--;
            }
            else{
                int area=(right-left)*height[left];
                ans=max(ans,area);
                left++;
            }
        }
        return ans;
    }
};
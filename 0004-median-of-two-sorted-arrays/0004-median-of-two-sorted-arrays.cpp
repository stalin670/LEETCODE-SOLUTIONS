class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final;
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                final.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                final.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n1){
            final.push_back(nums1[i]);
            i++;
        }

        while(j<n2){
            final.push_back(nums2[j]);
            j++;
        }

        int sz=n1+n2;

        if(sz&1){
            double ans=final[sz/2];
            return ans;
        }
        int p=sz/2;
        double ans=final[p-1]+final[p];

        return ans/2;
    
    }
};
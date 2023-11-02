class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int cnt1=0,cnt2=0;
        long long s1=0,s2=0;
        for(auto &it:nums1){
            if(it==0){
                cnt1++;
                it++;
            }
            s1+=it;
        }
        for(auto &it:nums2){
            if(it==0){
                cnt2++;
                it++;
            }
            s2+=it;
        }

        cout<<s1<<" "<<s2<<endl;

        if(cnt1==0 and cnt2==0 and s1!=s2) return -1;
        if(cnt1==0 and cnt2==0 and s1==s2) return s1;

        if(cnt1==0){
            if(s1<s2) return -1;
            else return s1;
        }
        if(cnt2==0){
            if(s2<s1) return -1;
            return s2;
        }

        return min(s1,s2)+abs(s1-s2);
    }
};
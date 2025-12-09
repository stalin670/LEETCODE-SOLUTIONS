class Solution {
public:


#define ll long long
    int specialTriplets(vector<int>& a) {
        /*
        3 <= n <= 1e5
        0 <= ai <= 1e5

        a1, a2, a3..........an

        i, j, k

        i < j < k

        ai = 2 * aj
        ak = 2 * aj

        brute force
        O(n ^ 3)
        O(1)

        [8,4,2,8,4]

        (8, [0, 3])
        (4, [1, 4])
        (2, [2])


        ai, aj, ak
        ai == ak == 2 * aj
        i < j < k

        a1, a2, a3..........an

        8, 8, 4, 2, 3, 8, 9, 7
        []    4  []

        Hashmap2
        key, value
        8 , 1
        4 , 0
        2 , 1
        3 , 1
        9 , 1
        7 , 1

        Hashmap1
        8 = 2

        index = 2, value = 4 = 4 * 2 = 8
        1st8, 2nd8, 4, 3rd8

        1st8, 4, 3rd8
        2nd8, 4, 3rd8


        

        */
    

    // int ans = 0;
    // for(int i = 0; i < n; i++) {
    //     for(int j = i + 1; j < n; j++) {
    //         for(int k = j + 1; k < n; k++) {
    //             if(a[i] == a[j] * 2 and a[k] = a[j] * 2)
    //                 ans++;
    //         }
    //     }
    // }
        int mod = 1000000007;

        ll ans = 0;
        int n = a.size();
        map<int, int> mp1, mp2;
        for(int i = 0; i < n; i++) {
            mp2[a[i]]++;
        }
        
        mp1[a[0]]++;
        mp2[a[0]]--;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                continue;
            }

            mp2[a[i]]--;


            int need = a[i] * 2;

            if(mp1.find(need) != mp1.end() && mp2.find(need) != mp2.end()) {
                ans = (ans + ((ll)mp1[need] * (ll)mp2[need])) % mod;
            }

            mp1[a[i]]++;
        }

        return ans;

    }
};
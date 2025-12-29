#define ll long long

ll min(ll a, ll b) {
    if(a < b) return a;
    return b;
}
ll max(ll a, ll b) {
    if(a > b) return a;
    return b;
}

long long maximumScore(int* nums, int n) {
    ll prefSum[n];
    ll suffMin[n];
    prefSum[0] = nums[0];
    suffMin[n - 1] = nums[n - 1];

    for(int i = 1; i < n; i++) {
        prefSum[i] = prefSum[i - 1] + nums[i];
    }

    for(int i = n - 2; i >= 0; i--) {
        suffMin[i] = min(suffMin[i + 1], nums[i]);
    }

    ll ans = -1000000000000000;
    for(int i = 0; i < n - 1; i++) {
        ans = max(ans, prefSum[i] - suffMin[i + 1]);
    }
    return ans;
}
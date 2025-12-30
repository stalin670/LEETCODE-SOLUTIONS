#define ll long long

ll max(ll a, ll b) {
    if(a > b) return a;
    return b;
}

ll min(ll a, ll b) {
    if(a < b) return a;
    return b;
}

long long maximumScore(int* arr, int n) {
    ll prefSum[n];
    ll suffMin[n];
    for(ll i = 0; i < n; i++) {
        if(i == 0) prefSum[0] = arr[0];
        else prefSum[i] = prefSum[i - 1] + arr[i];
    }
    for(ll i = n - 1; i >= 0; i--) {
        if(i == n - 1) suffMin[n - 1] = arr[n - 1];
        else suffMin[i] = min(suffMin[i + 1], arr[i]);
    }
    ll score = -10000000000000000;
    for(ll i = 0; i < n - 1; i++) {
        score = max(score, prefSum[i] - suffMin[i + 1]);
    }
    return score;
}
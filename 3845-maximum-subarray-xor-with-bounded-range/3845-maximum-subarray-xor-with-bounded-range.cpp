#pragma GCC optimize("O3", "unroll-loops")
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1000000000000000000LL
#define nline cout << "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define bg begin
#define lbd lower_bound
#define ubd upper_bound
#define pll pair<ll, ll>
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()
#define allR(x) (x).rbegin(), (x).rend()
#define TT ll t; cin >> t; while(t--)

using ll = long long;
using ull = unsigned long long;
using lld = long double;

#define looping(i, a, b) for (ll i = a; i < (b); i++)
#define loop(i, a) for (ll i = 0; i < (a); i++)
#define loopi(i, a) for(ll i = 0; i < a;)
#define loopg(i, a, b, k) for(ll i = a; i < b; i += k)
#define loopingd(i, a, b) for (ll i = (b) - 1; i >= a; i--)
#define loopd(i, a) for (ll i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

class Solution {
    struct TrieNode {
        int child[2];
        int mx;
        TrieNode() {
            child[0] = child[1] = 0;
            mx = -1;
        }
    };

    vector<TrieNode> trie;

    void insert(int val, int idx) {
        int cur = 0;
        trie[cur].mx = max(trie[cur].mx, idx);
        loopd(i, 15) {
            int bit = (val >> i) & 1;
            if (!trie[cur].child[bit]) {
                trie[cur].child[bit] = sz(trie);
                trie.pb(TrieNode());
            }
            cur = trie[cur].child[bit];
            trie[cur].mx = max(trie[cur].mx, idx);
        }
    }

    int query(int val, int lim) {
        int cur = 0, ans = 0;
        loopd(i, 15) {
            int bit = (val >> i) & 1;
            int want = 1 - bit;
            if (trie[cur].child[want] &&
                trie[trie[cur].child[want]].mx >= lim) {
                ans |= (1 << i);
                cur = trie[cur].child[want];
            } else {
                cur = trie[cur].child[bit];
            }
        }
        return ans;
    }

public:
    int maxXor(vector<int>& nums, int k) {
        ll n = sz(nums);
        trie.clear();
        trie.reserve(n * 16 + 2);
        trie.pb(TrieNode());

        vector<int> pref(n + 1, 0);
        loop(i, n) pref[i + 1] = pref[i] ^ nums[i];

        deque<ll> mx_dq, mn_dq;
        ll L = 0;
        int ans = 0;

        loop(j, n) {
            while (!mx_dq.empty() && nums[mx_dq.back()] <= nums[j])
                mx_dq.pop_back();
            mx_dq.pb(j);

            while (!mn_dq.empty() && nums[mn_dq.back()] >= nums[j])
                mn_dq.pop_back();
            mn_dq.pb(j);

            while (nums[mx_dq.front()] - nums[mn_dq.front()] > k) {
                if (mx_dq.front() == L) mx_dq.pop_front();
                if (mn_dq.front() == L) mn_dq.pop_front();
                L++;
            }

            insert(pref[j], j);
            ans = max(ans, query(pref[j + 1], L));
        }

        return ans;
    }
};

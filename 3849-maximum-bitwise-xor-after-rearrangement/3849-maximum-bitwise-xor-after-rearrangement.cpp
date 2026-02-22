#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cctype>
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

const ll dx[] = {0, 0, 1, -1};
const ll dy[] = {1, -1, 0, 0};
ll mod_power(ll a, ll b, ll m) { ll ans = 1; while (b) { if (b & 1) ans = ans * a % m; a = a * a % m; b >>= 1; } return ans; }
ll gcd (ll a, ll b) {  return b ? gcd (b, a % b) : a;  }
ll lcm (ll a, ll b) {  return (a * b) / gcd(a, b); }
ll mod_inv(ll x) { return mod_power(x, MOD - 2, MOD) % MOD; }
ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD) % MOD) % MOD; }
ll mod_div(ll a, ll b) { return mod_mul(a, mod_inv(b)) % MOD; }
ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
bool is1to9(char c) { return c >= '1' and c <= '9'; }
bool isaToz(char c) { return c >= 'a' and c <= 'z'; }
bool isprime(ll n) { for (ll i = 2; i * i <= n; ++i) { if (n % i == 0) { return false; } } return true; }
template <typename T> void chkmn(T &x, T y) { x = min(x, y); }
template <typename T> void chkmx(T &x, T y) { x = max(x, y); }
 

class Solution {
public:
    string maximumXor(string s, string t) {
        ll cnt_0 = count(all(t), '0');
        ll cnt_1 = count(all(t), '1');

        string ans = "";
        trav(ch, s) {
            if(ch == '1') {
                // need 0
                if(cnt_0 > 0) {
                    cnt_0--;
                    ans += "1";
                }
                else {
                    cnt_1--;
                    ans += "0";
                }
            }
            else {
                // need 1
                if(cnt_1 > 0) {
                    cnt_1--;
                    ans += "1";
                }
                else {
                    cnt_0--;
                    ans += "0";
                }
            }
            
        }
        return ans;
    }
};
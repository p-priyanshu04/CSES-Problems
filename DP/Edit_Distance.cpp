#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define set_bits __builtin_popcountll
#define prDouble(x) cout << fixed << setprecision(10) << x
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1000000007;
constexpr ll MOD2 = 998244353;

typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map<T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll binExpIter(ll a, ll b) { ll temp = 1; while (b > 0) { if (b & 1) temp = (temp * 1LL * a) % MOD2; a = (a * 1LL * a) % MOD2; b >>= 1; } return temp % MOD2; }
ll inv(ll n) { return binExpIter(n, MOD - 2) % MOD; }
ull __lcm(ull a, ull b) { return (a * b) / __gcd(a, b); }
ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mod_div(ll a, ll b) { return mod_mul(a, inv(b)); }

void solve() {
    ll i=0,j=0,n,m;
    string s,t;
    cin>>s>>t;
    n=sz(s);
    m=sz(t);
    vvll dp(n+1,vll(m+1,0));
    for(i=0;i<=n;i++) dp[i][0]=i;
    for(j=0;j<=m;j++) dp[0][j]=j;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(s[i-1]==t[j-1]) {
                dp[i][j]=dp[i-1][j-1];
            }
            else {
                if(i>0) dp[i][j]=dp[i-1][j]+1;
                if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                if(i>0 && j>0) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    cout << dp[n][m] << "\n";
    return;
}

int32_t main() {
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
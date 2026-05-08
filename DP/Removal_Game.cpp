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
    cin>>n;
    vll a(n);
    for(i=0;i<n;i++) cin>>a[i];
    vvll dp(n,vll(n,INT_MIN));
    for(i=0;i<n;i++) dp[i][i]=a[i];
    for(j=2;j<=n;j++) {
        for(i=0;i+j-1<n;i++) {
            ll l=i;
            ll r=i+j-1;
            ll t1=INT_MIN;
            ll t2=INT_MIN;
            if(l+1<n) t1=a[l]-dp[l+1][r];
            if(r-1>=0) t2=a[r]-dp[l][r-1];
            dp[l][r]=max(t1,t2);
        }
    }
    ll sum=0;
    for(i=0;i<n;i++) sum+=a[i];
    cout<<(sum+dp[0][n-1])/2<<endl;
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
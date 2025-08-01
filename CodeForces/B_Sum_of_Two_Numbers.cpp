// https://codeforces.com/problemset/problem/1788/B
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
// #define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define prec(n) fixed<<setprecision(n)
#define rep(a,b) for(auto &a : b)
#define rep1(n) for(ll i=0; i<(ll)(n); ++i)
#define case(i) cout << "Case " << i << ": "

const int MOD1 = 998244353;
const int N = 1e6+10;

#ifdef RASHEDUL
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef __int128 ell;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t<<',';}
void _print(int t) {cerr << t<<',';}
void _print(string t) {cerr << t<<',';}
void _print(char t) {cerr << t<<',';}
void _print(lld t) {cerr << t<<',';}
void _print(double t) {cerr << t<<',';}
void _print(ull t) {cerr << t<<',';}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}\n";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]\n";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]\n";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an array of size1 3
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
bool isPrime(ll num){if (num <= 1)return false;if (num <= 3)return true;if (num % 2 == 0 or num % 3 == 0)return false;for (int i = 5; i * i <= num; i += 6){if (num % i == 0 or num % (i + 2) == 0)return false;}return true;}
/*--------------------------------------------------------------------------------------------------------------------------*/

void preCal()
{
}
bool multiTest = true;
void solve(int testCase)
{
    string s, ans1, ans2;
    cin >> s;

    bool flag = true;
    rep(a, s)
    {
        if ((a - '0') % 2 == 0)
        {
            ans1.pb('0' + (a - '0') / 2);
            ans2.pb('0' + (a - '0') / 2);
        }
        else
        {
            if (flag)
            {
                ans1.pb('0' + (a - '0') / 2);
                ans2.pb('0' + (a - '0') / 2 + 1);
            }
            else
            {
                ans1.pb('0' + (a - '0') / 2 + 1);
                ans2.pb('0' + (a - '0') / 2);
            }
            flag = !flag;
        }
    }
    cout << stoll(ans1) << " " << stoll(ans2) << nline;
}
int main()
{
#ifdef RASHEDUL
    freopen("D://PROGRAMS//CONTEST_CodeForces_Folder//Error.txt", "w", stderr);
    freopen("D://PROGRAMS//CONTEST_CodeForces_Folder//in.in", "r", stdin);
    freopen("D:/PROGRAMS/CONTEST_CodeForces_Folder/out.out", "w", stdout);
    auto start1 = high_resolution_clock::now();
#endif
    fastio();
    preCal();

    int testCase = 1;
    int T{1};
    if (multiTest)
        cin >> T;
    while (T--)
    {
        solve(testCase++);
    }

#ifdef RASHEDUL
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << duration.count() << " ms" << endl;
#endif
}
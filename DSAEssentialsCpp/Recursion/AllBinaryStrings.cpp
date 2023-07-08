#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
static int my_speed_up = []()
{ ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
void binhelp(vector<string> &ans, string s, int i, int n)
{
    if (i == n)
    {
        ans.push_back(s);
        return;
    }
    //    cout << s << endl;
    binhelp(ans, s + '0', i + 1, n);
    binhelp(ans, s + '1', i + 1, n);
}
vector<string> AllBinary(int n)
{
    vector<string> ans;
    string s = "";
    binhelp(ans, s, 0, n);
    return ans;
}
int main()
{
    int n = 5;
    vector<string> bin = AllBinary(n);
    for (auto x : bin)
        cout << x << endl;
    return 0;
}
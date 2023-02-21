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
void helper(string s, int n, int i, vector<string> &ans)
{
    if (i == n)
    {
        ans.push_back(s);
        return;
    }
    string s1 = s;
    s1.push_back('0');
    helper(s1, n, i + 1, ans);

    if (i > 0 && s[i - 1] == '0')
    {
        s.push_back('1');
        helper(s, n, i + 1, ans);
    }
    else if (i == 0)
    {
        s.push_back('1');
        helper(s, n, i + 1, ans);
    }

    return;
}
vector<string> binaryStrings(int n)
{
    string s;
    vector<string> ans;
    helper(s, n, 0, ans);
    return ans;
}
int main()
{
    int n = 5;
    vector<string> ans = binaryStrings(n);
    for (auto x : ans)
        cout << x << endl;
    return 0;
}
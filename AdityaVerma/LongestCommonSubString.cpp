#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <climits>
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

int LCSubstring(string a, string b, int n, int m, int count)
{
    if (n == 0 or m == 0)
        return count;
    if (a[n - 1] == b[m - 1])
        return LCSubstring(a, b, n - 1, m - 1, count + 1);
    return max(LCSubstring(a, b, n - 1, m, 0), LCSubstring(a, b, n, m - 1, 0));
}

int LCSubStringDP(string a, string b, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int result = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return result;
}

int main()
{
    string a = "abcde";
    string b = "cd";
    int n = a.length();
    int m = b.length();
    int result = LCSubstring(a, b, n, m, 0);
    cout << result << endl;
    int result2 = LCSubStringDP(a, b, n, m);
    cout << result2 << endl;
    return 0;
}
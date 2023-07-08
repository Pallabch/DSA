#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>
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
int longestPalindromicSubsequence(string s, int i, int j)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (s[i] == s[j])
        return 2 + longestPalindromicSubsequence(s, i + 1, j - 1);
    return max(longestPalindromicSubsequence(s, i + 1, j), longestPalindromicSubsequence(s, i, j - 1));
}
// Memoized Solution
// int LPSMemo(string s, int i, int j, vector<vector<int>> &dp)
// {
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     if (i == j)
// }
int LPSDP(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i] == s[j])
                dp[i][j] = 2 + dp[i - 1][j + 1];
        }
    }
}
int main()
{
    string s = "agbcba";
    int n = s.length();
    cout << longestPalindromicSubsequence(s, 0, s.length() - 1);
    // cout << LPSMemo(s, 0, n - 1, dp);
    return 0;
}
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

int shortestCommonSuperSequenceRecurisve(string s1, string s2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (s1[m - 1] == s2[n - 1])
        return 1 + shortestCommonSuperSequenceRecurisve(s1, s2, m - 1, n - 1);
    else
        return 1 + min(shortestCommonSuperSequenceRecurisve(s1, s2, m - 1, n), shortestCommonSuperSequenceRecurisve(s1, s2, m, n - 1));
}
int SCSDP(string s1, string s2, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            if (!i)
                dp[i][j] = j;
            else if (!j)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
int LCS(string s1, string s2, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // Let us also print the shortest common supersequence from the above matrix
    string s = "";
    int i = m, j = n;
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s = s1[i - 1] + s;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            s = s1[i - 1] + s;
            i--;
        }
        else
        {
            s = s2[j - 1] + s;
            j--;
        }
    }
    while (i > 0)
    {
        s = s1[i - 1] + s;
        i--;
    }
    while (j > 0)
    {
        s = s2[j--] + s;
        j--;
    }
    cout << endl
         << s << endl;
    return dp[m][n];
}
int SCSLCSDP(string s1, string s2, int m, int n)
{
    return (m + n) - LCS(s1, s2, m, n);
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << shortestCommonSuperSequenceRecurisve(s1, s2, s1.length(), s2.length()) << endl;
    cout << SCSDP(s1, s2, s1.length(), s2.length()) << endl;
    cout << SCSLCSDP(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}
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

int LCSRecursive(string X, string Y, int n, int m)
{
    if (n == 0 or m == 0)
        return 0;
    if (X[n - 1] == Y[m - 1])
        return 1 + LCSRecursive(X, Y, n - 1, m - 1);
    return max(LCSRecursive(X, Y, n - 1, m), LCSRecursive(X, Y, n, m - 1));
}
int LCSMemoized(string X, string Y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 or m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (X[n - 1] == Y[m - 1])
        return dp[n][m] = 1 + LCSMemoized(X, Y, n - 1, m - 1, dp);
    return dp[n][m] = max(LCSMemoized(X, Y, n - 1, m, dp), LCSMemoized(X, Y, n, m - 1, dp));
}

int LCSDP(string X, string Y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

string LCSDPStringReturn(string X, string Y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // Printing Functionality for the LCS
    int i = n, j = m;
    string s = "";
    while (i > 0 and j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            s = X[i - 1] + s;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }
    return s;
}
int main()
{
    string X = "GeeksforGeeks";
    int n = X.size();
    string Y = "GeeksQuiz";
    int m = Y.size();
    cout << LCSRecursive(X, Y, n, m) << endl;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << LCSMemoized(X, Y, n, m, dp) << endl;
    cout << LCSDP(X, Y, n, m) << endl;
    cout << LCSDPStringReturn(X, Y, n, m) << endl;
    return 0;
}
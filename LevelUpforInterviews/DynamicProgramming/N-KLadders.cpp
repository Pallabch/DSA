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
int countWays(int n, int k)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    int ans = 0;
    for (int i = 1; i <= k; i++)
        ans += countWays(n - i, k);
    return ans;
}
int countWaysTD(int n, int k, int *dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != 0)
        return dp[n];
    int ans = 0;
    for (int i = 1; i <= k; i++)
        ans += countWays(n - i, k);
    return dp[n] = ans;
}

int countWaysBU(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 0;
    for (int i = 1; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }
    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] + dp[i - k - 1];
    }
    return dp[n];
}

int main()
{
    int n = 4, k = 3;
    cout << countWays(n, k) << endl;
    int dp[1000] = {0};
    cout << countWaysTD(n, k, dp) << endl;
    cout << countWays(n, k) << endl;
    return 0;
}
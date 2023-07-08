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

int unboundedKnapsackRecursive(int W, int wt[], int val[], int idx)
{
    if (idx < 0)
        return 0;
    // This is an alternate base case for the <0 case
    //  if (idx == 0)
    //  {
    //      return (W / wt[0]) * val[0];
    //  }
    if (W < 0)
        return 0;
    int take = INT_MIN;
    if (wt[idx] <= W)
        take = val[idx] + unboundedKnapsackRecursive(W - wt[idx], wt, val, idx);
    int donttake = unboundedKnapsackRecursive(W, wt, val, idx - 1);
    return max(take, donttake);
}
int unboundedKnapsackDP(int W, int wt[], int val[], int n)
{
    // Similar Matrix
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    // We fill the matrix
    // If weight of bag is 0 or number of items is 0 then we obviously can't take the item
    // So everything is 0
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int W = 8;
    int val[] = {15, 50, 60, 90};
    int wt[] = {1, 3, 4, 5};
    int n = sizeof(val) / sizeof(val[0]);

    cout << unboundedKnapsackRecursive(W, wt, val, n - 1) << endl;
    cout << unboundedKnapsackDP(W, wt, val, n);
    return 0;
    return 0;
}
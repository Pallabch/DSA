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
// Recursive Solution with arrays with n as index
int knapSack(int W, int weight[], int profit[], int n)
{
    if (n == 0 or W == 0)
        return 0;
    if (weight[n - 1] <= W)
        return max(knapSack(W, weight, profit, n - 1), profit[n - 1] + knapSack(W - weight[n - 1], weight, profit, n - 1));
    else
        return knapSack(W, weight, profit, n - 1);
}
// Recursive Solution with arrays with i as index
int knapSack2(int W, int weight[], int profit[], int i, int n)
{
    if (i == n or W == 0)
        return 0;
    if (weight[i] <= W)
        return max(knapSack2(W, weight, profit, i + 1, n), profit[i] + knapSack2(W - weight[i], weight, profit, i + 1, n));
    else
        return knapSack2(W, weight, profit, i + 1, n);
}
// Memoisation Solution
int knapSack3(int W, int weight[], int profit[], int n, vector<vector<int>> &dp)
{
    if (W == 0 or n == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (weight[n - 1] <= W)
        dp[n][W] = max(knapSack3(W, weight, profit, n - 1, dp), profit[n - 1] + knapSack3(W - weight[n - 1], weight, profit, n - 1, dp));
    else
        dp[n][W] = knapSack3(W, weight, profit, n - 1, dp);
    return dp[n][W];
}
// Top Down DP best DP
int knapSack4(int W, int weight[], int profit[], int n)
{
    // Convert the Base Case into initialization
    // First We create the matrix
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (weight[i - 1] <= W)
                dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i - 1][j - weight[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    vector<int> v_profit = {10, 20, 30};
    vector<int> v_weight = {5, 10, 15};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n) << endl;
    cout << knapSack2(W, weight, profit, 0, n) << endl;
    // For the memoisation Problem we need to initialise a matrix first and then pass it
    // Lets do it using vectors as I am comfortable with vectors otherwise there are too many initializations
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    // next we need to pass it to the function so that the recursion states could be maintained
    cout << knapSack3(W, weight, profit, n, dp) << endl;
    cout << knapSack4(W, weight, profit, n) << endl;
    return 0;
}
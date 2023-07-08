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

int findLowestCoinsRecursive(vector<int> coins, int amount, int index)
{
    if (index < 0 or amount < 0)
        return INT_MAX - 1;
    if (amount == 0)
        return 0;
    int res = -1;
    if (coins[index] <= amount)
    {
        int take = 1 + findLowestCoinsRecursive(coins, amount - coins[index], index);
        int donttake = findLowestCoinsRecursive(coins, amount, index - 1);
        res = min(take, donttake);
    }
    else
    {
        int donttake = findLowestCoinsRecursive(coins, amount, index - 1);
        res = donttake;
    }
    return res;
}

int minCoinsRecursive(vector<int> coins, int amount, int index)
{
    int result = findLowestCoinsRecursive(coins, amount, index);
    return result == INT_MAX - 1 ? -1 : result;
}

int minCoinsDP(vector<int> coins, int amount)
{
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    // We fill the columns 1-amount with inifinity because with no elements we wil require an infinite amount of it
    for (int i = 1; i < dp[0].size(); i++)
        dp[0][i] = INT_MAX - 1;
    // Now we can start filling up the matrix
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (coins[i - 1] <= amount)
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[coins.size()][amount];
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int amount = 5;
    cout << minCoinsRecursive(coins, amount, coins.size() - 1) << endl;
    cout << minCoinsDP(coins, amount) << endl;
    // cout << minCoinssDP(coins, amount);
    return 0;
}
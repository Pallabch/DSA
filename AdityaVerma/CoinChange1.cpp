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

int maxWaysRecursive(vector<int> coins, int amount, int index)
{
    if (index < 0)
        return 0;
    if (amount == 0)
        return 1;
    if (amount < 0)
        return 0;
    int donttake = maxWaysRecursive(coins, amount, index - 1);
    int take = 0;
    if (coins[index] <= amount)
        take = maxWaysRecursive(coins, amount - coins[index], index);
    return take + donttake;
}
void print(vector<vector<int>> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}
int maxWaysDP(vector<int> coins, int amount)
{
    // We create a matrix of coins and possible amounts
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    // First column should be 0 since if the amount of 0 you don't need any coins amirite
    for (int i = 0; i < dp.size(); i++)
        dp[i][0] = 1;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    print(dp);
    return dp[coins.size()][amount];
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int amount = 5;
    cout << maxWaysRecursive(coins, amount, coins.size() - 1) << endl;
    cout << maxWaysDP(coins, amount);
    return 0;
}
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
int maxProfit(vector<int> &prices)
{
    int maxProfit = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            maxProfit = max(prices[j] - prices[i], maxProfit);
        }
    }
    if (maxProfit <= 0)
        return 0;
    else
        return maxProfit;
}
int maxProfitDP(vector<int> prices)
{
    int buyPrice = prices[0];
    int maxProfit = 0, profit = INT_MIN;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] >= buyPrice)
        {
            profit = prices[i] - buyPrice;
        }
        maxProfit = max(maxProfit, profit);
        buyPrice = min(buyPrice, prices[i]);
    }
    return maxProfit;
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
    cout << maxProfitDP(prices) << endl;

    return 0;
}
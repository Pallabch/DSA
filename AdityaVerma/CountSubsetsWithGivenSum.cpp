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
// Recurisve Solution
int findWaysRecursive(vector<int> arr, int sum, int n)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (n < 0)
        return 0;
    int take = findWaysRecursive(arr, sum - arr[n - 1], n - 1);
    int donttake = findWaysRecursive(arr, sum, n - 1);
    return take + donttake;
}
// DP Solution
int findWaysDP(vector<int> arr, int sum)
{
    vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, 0));
    // Initialization
    // If sum is 0 then it is always possible and hence the count is 1
    for (int i = 0; i < dp.size(); i++)
        dp[i][0] = 1;
    // Rest is same as subset sum DP
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    print(dp);
    cout << endl;
    return dp[arr.size()][sum];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int sum = 3;
    // cout << "The number of subsets found are " << findWaysRecursive(arr, sum, arr.size()) << endl;
    cout << "The number of subsets found are " << findWaysDP(arr, sum) << endl;

    return 0;
}
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
bool isSubsetSumRecursive(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (sum < 0)
        return false;
    if (n == 0)
        return false;
    if (set[n - 1] > sum)
        return isSubsetSumRecursive(set, n - 1, sum);
    bool take = isSubsetSumRecursive(set, n - 1, sum - set[n - 1]);
    bool donttake = isSubsetSumRecursive(set, n - 1, sum);
    return (take or donttake);
}
bool isSubsetSumDP(int set[], int n, int sum)
{
    // We need to initialize a matrix with n+1 rows and 0 to sum columns
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    // First Column must be set to true since if the sum is 0 an empty set is always possible
    for (int i = 0; i < dp[0].size(); i++)
        dp[0][i] = true;
    // Next We need to start filling up the table
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (set[i - 1] < sum)
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - set[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2}, sum = 9;
    int n = sizeof(set) / sizeof(int);
    cout << isSubsetSumRecursive(set, n, sum) << endl;
    cout << isSubsetSumDP(set, n, sum) << endl;
    return 0;
}
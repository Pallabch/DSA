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
// DP Solution
int countSubsetSumDP(vector<int> arr, int n, int sum)
{
    // We need to initialize a matrix with n+1 rows and sum+1 cols
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    // If the sum is 0 we know that an empty set means it is possible
    // Therefore when sum is 0 we initialize the column with 1's
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = 1;
    }
    // Otherwise we start filling up the table
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
    return dp[n][sum];
}

// Recurisve Version
int countSubsetSumRecursive(vector<int> arr, int n, int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (n < 0)
        return 0;
    int take = countSubsetSumRecursive(arr, n - 1, sum - arr[n - 1]);
    int donttake = countSubsetSumRecursive(arr, n - 1, sum);
    return take + donttake;
}
int CountSubsetsRecursive(vector<int> arr, int n, int diff)
{
    // Find the sum of the array
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    // In order to find the subsets S1 and S2 we know that
    // S1-S2 = diff
    // S1+S2 = sum
    // 2S1 = diff+sum
    // S1 = (diff+sum)/2;
    int expectedSum = (diff + sum) / 2;
    int result = countSubsetSumDP(arr, n, expectedSum);
    return result;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1, 2};
    int n = arr.size();
    int diff = 1;
    int count = CountSubsetsRecursive(arr, n, diff);
    cout << "The number of subsets with the given diff is " << count << endl;
    return 0;
}
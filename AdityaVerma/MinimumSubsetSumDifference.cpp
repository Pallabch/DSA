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
int findMinRecHelper(int arr[], int n, int sumCalculated, int sumTotal)
{
    if (n == 0)
        return abs((sumTotal - sumCalculated) - sumCalculated);
    return min(findMinRecHelper(arr, n - 1, arr[n - 1] + sumCalculated, sumTotal), findMinRecHelper(arr, n - 1, sumCalculated, sumTotal));
}
int findMinRecursive(int arr[], int n)
{
    // Find the total sum
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];
    return findMinRecHelper(arr, n, 0, range);
}
int findMinDP(int arr[], int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];
    // Let's find the Last row of the subset sum matrix which would give us the possible subset sum values
    // This is just a rewrite of the subset sum problem
    vector<vector<bool>> dp(n + 1, vector<bool>(range + 1, false));
    // Again Initialize the vector
    // We know that if the sum is 0 then an empty vector means that the sum is possible
    for (int i = 0; i < dp.size(); i++)
        dp[i][0] = true;
    // Now we can start working on the matrix computation
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // The subset sum matrix is prepared the last rows gives us critical information which we're gonna use
    int diff = INT_MAX;
    for (int j = range / 2; j >= 0; j--)
    {
        if (dp[n][j] == true)
            diff = min(diff, range - 2 * j);
    }
    return diff;
}
int main()
{
    int arr[] = {1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between two sets is " << findMinRecursive(arr, n) << endl;
    cout << "The minimum difference between two sets is " << findMinDP(arr, n) << endl;
    return 0;
}
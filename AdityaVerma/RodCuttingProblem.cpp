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

int cutRodRecursive(vector<int> arr, int index, int n)
{
    if (index == 0)
        return 0;
    int notcut = cutRodRecursive(arr, index - 1, n);
    int cut = INT_MIN;
    int rod_length = index + 1;
    if (rod_length <= n)
    {
        cut = arr[index] + cutRodRecursive(arr, index, n - rod_length);
    }
    return max(cut, notcut);
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
int cutRodDP(vector<int> price, int size)
{
    // We will need a DP Table
    // We don't need a 0 length here or we can have it
    vector<vector<int>> dp(size + 1, vector<int>(price.size() + 1, 0));
    // Fill the table
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (i <= j)
                dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // print(dp);
    return dp[size][size];
}
int cutRodDP2(vector<int> price, int size)
{
    // Let's make a length array as well
    vector<int> length(price.size(), 0);
    for (int i = 0; i < length.size(); i++)
        length[i] = i + 1;
    vector<vector<int>> dp(length.size() + 1, vector<int>(price.size() + 1, 0));
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (length[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i - 1][j - length[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[length.size()][size];
}
int main()
{
    vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = arr.size();
    cout << "Maximum Obtainable Value is " << cutRodRecursive(arr, size - 1, size) << endl;
    cout << "Maximum Obtainable Value is " << cutRodDP(arr, size) << endl;
    cout << "Maximum Obtainable Value is " << cutRodDP2(arr, size) << endl;

    return 0;
}
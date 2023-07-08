#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>
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
void print(vector<vector<int>> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << "   ";
        }
        cout << endl;
    }
}
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int minPalPartition(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = 1 + minPalPartition(s, i, k) + minPalPartition(s, k + 1, j);
        ans = min(ans, temp);
    }
    return ans;
}
int minPalPartitionMemo(string s, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = 1 + minPalPartition(s, i, k) + minPalPartition(s, k + 1, j);
        ans = min(ans, temp);
    }
    cout << endl;
    cout << endl;
    return dp[i][j] = ans;
}
int minPalPartitionTD(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<vector<bool>> palindrome(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][i] = 0;
        palindrome[i][i] = true;
    }
    for (int L = 1; L < n - 1; L++)
    {
        for (int i = 1; i < n - L; i++)
        {
            int j = i + L;
            if (L == 2)
            {
                palindrome[i][j] = s[i] == s[j];
            }
            else
            {
                palindrome[i][j] = s[i] == s[j] and palindrome[i + 1][j - 1];
            }
            if (palindrome[i][j] == true)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                }
            }
        }
    }
    cout << endl;
    print(dp);
    return dp[1][n - 1];
}
int main()
{
    string s = "aab";
    cout << minPalPartition(s, 0, s.length() - 1) << endl;
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << minPalPartitionMemo(s, 0, n - 1, dp) << endl;
    cout << endl;
    print(dp);
    cout << endl;
    cout << minPalPartitionTD(s) << endl;
    return 0;
}
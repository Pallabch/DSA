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
int MatrixChainOrder(vector<int> mat, int i, int j)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = MatrixChainOrder(mat, i, k) + MatrixChainOrder(mat, k + 1, j) + mat[i - 1] * mat[k] * mat[j];
        ans = min(ans, temp);
    }
    return ans;
}
int MatrixChainOrderMemo(vector<int> mat, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != 0)
        return dp[i][j];
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = MatrixChainOrderMemo(mat, i, k, dp) + MatrixChainOrderMemo(mat, k + 1, j, dp) + mat[i - 1] * mat[k] * mat[j];
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}
int MatrixChainOrderBU(vector<int> mat)
{
    int n = mat.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> S(n, vector<int>(n, 0));
    // First loop is for chain length
    for (int L = 1; L < n - 1; L++)
    {
        for (int i = 1; i < n - L; i++)
        {
            int j = i + L;
            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int temp = dp[i][k] + dp[k + 1][j] + mat[i - 1] * mat[k] * mat[j];
                if (temp < mini)
                {
                    mini = temp;
                    S[i][j] = k;
                }
            }
            dp[i][j] = mini;
        }
    }
    print(S);
    return dp[1][n - 1];
}
int main()
{
    vector<int> mat = {1, 2, 3, 4, 3};
    cout << MatrixChainOrder(mat, 1, mat.size() - 1) << endl;
    int n = mat.size(); // 5
    vector<vector<int>> dp(n, vector<int>(n, 0));
    cout << MatrixChainOrderMemo(mat, 1, n - 1, dp) << endl;
    cout << MatrixChainOrderBU(mat) << endl;
    return 0;
}
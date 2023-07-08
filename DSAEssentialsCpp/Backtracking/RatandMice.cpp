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
void helper(vector<string> arr, vector<vector<int>> &board, vector<vector<int>> &ans, int i, int j, int n, int m)
{
    // When we reach the destination we just copy the board at that point
    if (i == n and j == m)
    {
        for (int k = 0; k <= n; k++)
        {
            for (int l = 0; l <= m; l++)
            {
                ans[k][l] = board[k][l];
            }
        }
        return;
    }
    // Otherwise we need to do recursion based upon available movements
    if (i != n and arr[i + 1][j] == 'O' and board[i + 1][j] == 0)
    {
        board[i + 1][j] = 1;
        helper(arr, board, ans, i + 1, j, n, m);
        board[i + 1][j] = 0;
    }
    if (i > 0 and arr[i - 1][j] == 'O' and board[i - 1][j] == 0)
    {
        board[i - 1][j] = 1;
        helper(arr, board, ans, i - 1, j, n, m);
        board[i - 1][j] = 0;
    }
    if (j != m and arr[i][j + 1] == 'O' and board[i][j + 1] == 0)
    {
        board[i][j + 1] = 1;
        helper(arr, board, ans, i, j + 1, n, m);
        board[i][j + 1] = 0;
    }
    if (j > 0 and arr[i][j - 1] == 'O' and board[i][j - 1] == 0)
    {
        board[i][j - 1] = 1;
        helper(arr, board, ans, i, j - 1, n, m);
        board[i][j - 1] = 0;
    }
    return;
}
vector<vector<int>> ratAndMice(vector<string> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    board[0][0] = 1;
    helper(arr, board, ans, 0, 0, n - 1, m - 1);
    return ans;
}
int main()
{
    vector<string> arr = {"OXOO", "OOOX", "XOXO", "XOOX", "XXOO"};
    vector<vector<int>> solution = ratAndMice(arr);
    print(solution);
    return 0;
}
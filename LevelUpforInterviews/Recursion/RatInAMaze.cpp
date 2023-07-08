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
bool helper(vector<vector<char>> c, vector<int> &result, int i, int j, int n, vector<vector<int>> &path)
{
    if (c[i][j] == 'X')
        return false;
    // Base Case
    if (i == n - 1 and j == n - 1)
    {
        return true;
    }
    if (i > n - 1 or j > n - 1)
        return false;
    // Otherwise take right step
    result.push_back(path[i][j + 1]);
    bool right = helper(c, result, i, j + 1, n, path);
    if (right)
        return true;
    else
    {
        result.pop_back();
        result.push_back(path[i + 1][j]);
        bool down = helper(c, result, i + 1, j, n, path);
        if (down)
            return down;
    }
    result.pop_back();
    return false;
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
vector<int> findPath(int n, vector<vector<char>> c, vector<vector<int>> &path)
{
    vector<int> result;
    result.push_back(1);
    helper(c, result, 0, 0, n, path);
    return result;
}
int main()
{
    vector<vector<char>> maze = {{'O', 'O', 'O'}, {'O', 'X', 'X'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}};
    int n = 3;
    int numbers = 1;
    vector<vector<int>> path(n, vector<int>(n, 0));
    for (int i = 0; i < path.size(); i++)
    {
        for (int j = 0; j < path[i].size(); j++)
        {
            path[i][j] = numbers++;
        }
    }
    print(path);
    cout << endl;
    vector<int> result = findPath(n, maze, path);

    for (int i = 0; i < result.size(); i++)
        //     // cout << "(" << result[i].first << "," << result[i].second << ")"<< " ";
        cout << result[i] << " ";
    return 0;
}
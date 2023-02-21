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
void spiralprint(vector<vector<int>> arr)
{
    int rows = arr.size();
    int columns = arr[0].size();
    int startRow = 0;
    int endRow = rows - 1;
    int startCol = 0;
    int endCol = columns - 1;
    while (startCol <= endCol and startRow <= endRow)
    {
        // Start Row
        for (int i = startCol; i <= endCol; i++)
        {
            cout << arr[startRow][i] << " ";
        }
        // End Column
        for (int i = startRow + 1; i <= endRow; i++)
        {
            cout << arr[i][endCol] << " ";
        }
        // End Row
        for (int i = endCol - 1; i >= startCol; i--)
        {
            cout << arr[endRow][i] << " ";
        }
        // Start Column
        for (int i = endRow - 1; i >= startRow + 1; i--)
        {
            cout << arr[i][startCol] << " ";
        }
        startRow++;
        endCol--;
        endRow--;
        startCol++;
    }
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    //{9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}
    spiralprint(arr);
    return 0;
}
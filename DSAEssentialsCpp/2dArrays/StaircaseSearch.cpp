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
pair<int, int> staircasesearch(vector<vector<int>> arr, int key)
{
    if (key < arr[0][0] or key > arr[arr.size() - 1][arr[0].size() - 1])
        return {-1, -1};
    int i = 0, j = arr[0].size() - 1;
    while (i <= arr.size() - 1 and j >= 0)
    {
        if (arr[i][j] == key)
            return {i, j};
        else if (arr[i][j] > key)
            j--;
        else
            i++;
    }
    return {-1, -1};
}
int main()
{
    vector<vector<int>> arr = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    int key = 33;
    cout << staircasesearch(arr, key).first << " " << staircasesearch(arr, key).second;
    return 0;
}
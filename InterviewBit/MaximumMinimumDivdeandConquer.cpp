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
class Pair
{
public:
    int max;
    int min;
};
Pair getMinMax(vector<int> arr, int low, int high)
{
    Pair minmax, Lmm, Rmm;
    if (low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }
    if (high == low + 1)
    {
        if (arr[high] > arr[low])
        {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        else
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        return minmax;
    }
    int mid = (high - low) / 2 + low;
    Lmm = getMinMax(arr, low, mid);
    Rmm = getMinMax(arr, mid + 1, high);
    if (Lmm.min < Rmm.min)
        minmax.min = Lmm.min;
    else
        minmax.min = Rmm.min;
    if (Lmm.max > Rmm.max)
        minmax.max = Lmm.max;
    else
        minmax.max = Rmm.max;
    return minmax;
}
int main()
{
    vector<int> arr = {1000, 11, 445, 1, 330, 3000};
    Pair p = getMinMax(arr, 0, arr.size() - 1);
    cout << p.max << " " << p.min;
    return 0;
}
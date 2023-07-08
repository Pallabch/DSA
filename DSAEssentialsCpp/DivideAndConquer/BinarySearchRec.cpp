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
int binarysearchhelper(vector<int> v, int low, int high, int key)
{
    if (high >= low)
    {
        int mid = (high - low) / 2 + low;
        // cout << v[mid] << endl;
        // cout << key << endl;
        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] < key)
        {
            // Search left
            return binarysearchhelper(v, mid + 1, high, key);
        }
        else
        {
            // Search Right

            return binarysearchhelper(v, low, mid - 1, key);
        }
    }
    return -1;
}
int binarySearch(vector<int> v, int x)
{
    int low = 0;
    int high = v.size();
    return binarysearchhelper(v, low, high - 1, x);
}
int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    int key = 3;
    int index = binarySearch(arr, key);
    cout << index << endl;
    return 0;
}
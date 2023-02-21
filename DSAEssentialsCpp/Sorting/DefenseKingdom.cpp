#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
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
int defkin(int W, int H, vector<pair<int, int>> position)
{
    vector<int> x, y;
    x.push_back(0);
    y.push_back(0);
    for (pair<int, int> p : position)
    {
        x.push_back(p.first);
        y.push_back(p.second);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i : x)
        cout << " " << i << " ";
    cout << endl;
    for (int i : y)
        cout << " " << i << " ";
    cout << endl;
    int maxX = INT_MIN, maxY = INT_MIN;
    for (int i = 1; i < x.size(); i++)
        maxX = max(maxX, x[i] - x[i - 1] - 1);
    for (int i = 1; i < y.size(); i++)
        maxY = max(maxY, y[i] - y[i - 1] - 1);
    return maxX * maxY;
}
int main()
{
    int W = 15, H = 8;
    vector<pair<int, int>> crossBowTowerCooridnate = {make_pair(3, 8), make_pair(11, 2), make_pair(8, 6)};
    cout << defkin(W, H, crossBowTowerCooridnate);
    return 0;
}
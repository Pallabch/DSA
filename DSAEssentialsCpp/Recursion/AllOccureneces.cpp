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
void helper(vector<int> v, int k, int i, vector<int> &ans)
{
    if (i == v.size())
        return;
    if (v[i] == k)
        ans.push_back(i);
    helper(v, k, ++i, ans);
}
vector<int> findAllOccurences(int k, vector<int> v)
{
    vector<int> ans;
    helper(v, k, 0, ans);
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 5, 3, 1, 2, 3, 8, 6, 3, 6, 7, 9};
    vector<int> ans = findAllOccurences(3, arr);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
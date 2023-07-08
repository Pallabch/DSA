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
void subsetsUtil(vector<int> &A, vector<vector<int>> &res, vector<int> &subset, int index)
{
    // Base Case
    if (index < 0)
    {
        res.push_back(subset);
        return;
    }
    // Either take the index in the subset
    subset.push_back(A[index]);
    subsetsUtil(A, res, subset, index - 1);
    subset.pop_back();
    subsetsUtil(A, res, subset, index - 1);
    return;
}
vector<vector<int>> subsets(vector<int> arr)
{
    vector<vector<int>> result;
    vector<int> subset;
    subsetsUtil(arr, result, subset, arr.size() - 1);
    return result;
}

int main()
{
    // find the subsets of below vector.
    vector<int> array = {1, 2, 3};

    // res will store all subsets.
    // O(2 ^ (number of elements inside array))
    // because total number of subsets possible
    // are O(2^N)
    vector<vector<int>> res = subsets(array);
    sort(res.begin(), res.end());
    // Print result
    for (int i = 0; i < res.size(); i++)
    {
        sort(res[i].begin(), res[i].end());
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
    return 0;
}
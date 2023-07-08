#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <set>
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
void helper(set<vector<int>> &s, vector<int> ans, vector<int> &nums, int i)
{
    // Base Case
    if (i == nums.size())
    {
        sort(ans.begin(), ans.end());
        s.insert(ans);
        return;
    }
    // Recurisve Case
    // Either include the number in the set or don't
    ans.push_back(nums[i]);
    helper(s, ans, nums, i + 1);
    ans.pop_back();
    helper(s, ans, nums, i + 1);
}
vector<vector<int>> uniqueSubsets(vector<int> nums)
{
    vector<vector<int>> result;
    vector<int> ans;
    set<vector<int>> s;
    s.clear();
    helper(s, ans, nums, 0);
    for (auto x : s)
        result.push_back(x);
    return result;
}
int main()
{
    vector<int> nums = {4, 1, 0};
    vector<vector<int>> subsets = uniqueSubsets(nums);
    for (auto x : subsets)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << "Size of set is " << subsets.size() << endl;
    return 0;
}
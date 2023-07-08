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
    cout << endl;
}
void helper(vector<vector<int>> &ans, int s, int e, vector<int> &nums)
{
    if (s == e)
    {
        ans.push_back(nums);
        return;
    }
    for (int i = s; i <= e; i++)
    {
        swap(nums[i], nums[s]);
        helper(ans, s + 1, e, nums);
        swap(nums[i], nums[s]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    int s = 0;
    int e = nums.size() - 1;
    vector<vector<int>> ans;
    helper(ans, s, e, nums);
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = permute(arr);
    print(ans);
    return 0;
}
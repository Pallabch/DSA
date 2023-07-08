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
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // Merge the 2 arrays first
    // for (int i = m; i < m + n; i++)
    //     nums1[i] = nums2[i - n];
    for (int i = m, j = 0; i < m + n and j < n; i++, j++)
        nums1[i] = nums2[j];
    // Maintain pointers
    // int i = 0, j = m;
    // while (i < m and j < m + n)
    // {
    //     if (nums1[i] > nums1[j])
    //     {
    //         swap(nums1[i++], nums1[j++]);
    //     }
    //     else
    //     {
    //         i++;
    //     }
    // }
    return;
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3, n = 3;
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, m, nums2, n);
    for (auto x : nums1)
        cout
            << x << " ";
    return 0;
}
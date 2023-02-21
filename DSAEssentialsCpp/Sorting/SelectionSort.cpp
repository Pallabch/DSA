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
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int current_element = arr[i];
        int min_position = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min_position])
            {
                min_position = j;
            }
        }
        swap(arr[min_position], arr[i]);
    }
}
int main()
{
    int arr[] = {10, 12, 5, 4, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);
    selection_sort(arr, n);
    for (int i : arr)
        cout << i << " ";
    return 0;
    return 0;
    return 0;
}
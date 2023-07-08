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
void merge(vector<int> &arr, int start, int end)
{
    int i = start;
    int mid = (end - start) / 2 + start;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid and j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= end)
        temp.push_back(arr[j++]);
    int k = 0;
    for (int idx = start; idx <= end; idx++)
        arr[idx] = temp[k++];
}
void merge(vector<int> &arr, int start, int end)
{
    int mid = (end - start) / 2 + start;
    vector<int> L, R;
    for (int i = start; i <= mid; i++)
        L.push_back(arr[i]);
    for (int j = mid + 1; j <= end; j++)
        R.push_back(arr[j]);
    int i = 0, j = 0, k = start;
    while (i < L.size() and j < R.size())
    {
        if (L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < L.size())
        arr[k++] = L[i++];
    while (j < R.size())
        arr[k++] = R[j++];
}
void mergesort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = (end - start) / 2 + start;
    // Mergesort on the left array
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start, end);
}

// void mergesort(vector<int> &arr, int start, int end)
// {
//     if (start >= end)
//         return;
//     int mid = (end - start) / 2 + start;
//     // Calling mergesort on the left subarray
//     mergesort(arr, start, mid);
//     // Calling mergesort on the right subarray
//     mergesort(arr, mid + 1, end);
//     // Merging the 2 subarrays
//     merge(arr, start, end);
// }
int main()
{
    vector<int> arr = {5, 1, 8, 9, 7, 4, 2, 3, 6};
    mergesort(arr, 0, arr.size() - 1);
    for (auto x : arr)
        cout << x << " ";
    return 0;
}
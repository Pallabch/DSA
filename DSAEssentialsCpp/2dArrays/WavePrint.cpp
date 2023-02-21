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
vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    vector<int> answer;
    int startRow = 0;
    int endRow = m - 1;
    int endCol = n - 1;
    int startCol = 0;
    while (endCol >= startCol)
    {
        for (int i = startRow; i <= endRow; i++)
        {
            if (endCol < startCol)
                break;
            answer.push_back(arr[i][endCol]);
        }
        endCol--;
        for (int i = endRow; i >= startRow; i--)
        {
            if (endCol < startCol)
                break;
            answer.push_back(arr[i][endCol]);
        }
        endCol--;
    }
    return answer;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    //{9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}
    vector<int> answer = WavePrint(4, 4, arr);
    for (int x : answer)
        cout << x << " ";
    return 0;
}
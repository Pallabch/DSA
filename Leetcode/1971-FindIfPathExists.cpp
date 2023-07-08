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
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    stack<int> s;
    vector<bool> visited(n, false);
    s.push(source);
    visited[source] = true;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i][0] == top and !visited[edges[i][1]])
            {
                s.push(edges[i][1]);
                visited[edges[i][1]] = true;
            }
        }
    }
    for (auto x : visited)
        cout << x << " ";
    cout << endl;
    return visited[destination];
}
int main()
{
    vector<vector<int>> edges = {{0, 7}, {0, 8}, {6, 1}, {2, 0}, {0, 4}, {5, 8}, {4, 7}, {1, 3}, {3, 5}, {6, 5}};
    int n = 10;
    cout << validPath(n, edges, 7, 5);
    return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
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
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
            l[j].push_back(i);
    }
    void printAdjacencyList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto x : l[i])
                cout << x << ",";
            cout << endl;
        }
    }
    void dfshelper(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << ",";
        for (auto n : l[node])
        {
            if (!visited[n])
                dfshelper(n, visited);
        }
        return;
    }
    void dfs(int source)
    {
        vector<bool> visited(V, false);
        dfshelper(source, visited);
    }
    void dfsstack(int source)
    {
        stack<int> s;
        vector<bool> visited(V, false);
        s.push(source);
        visited[source] = true;
        while (!s.empty())
        {
            int top = s.top();
            cout << top << ",";
            s.pop();
            for (auto neighbour : l[top])
            {
                if (!visited[neighbour])
                {
                    s.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return;
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.printAdjacencyList();
    g.dfs(1);
    cout << endl;
    g.dfsstack(1);
    return 0;
}
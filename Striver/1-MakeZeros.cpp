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
void setZeroes(vector<vector<int>> &matrix)
{
    bool row = false, col = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                    row = true;
                if (j == 0)
                    col = true;
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    print(matrix);
    // if (col)
    // {
    //     for (int i = 0; i < matrix.size(); i++)
    //         matrix[i][0] = 0;
    // }
    // if (row)
    // {
    //     for (int j = 0; j < matrix[0].size(); j++)
    //         matrix[0][j] = 0;
    // }
}
void setZeroes1(vector<vector<int>> &matrix)
{
    bool isRow = false, isCol = false;
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                    isRow = true;
                if (j == 0)
                    isCol = true;
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][0] == 0 or matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    print(matrix);
    if (isCol)
    {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }
    if (isRow)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            matrix[0][j] = 0;
    }
}
int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes1(matrix);
    print(matrix);
    return 0;
}
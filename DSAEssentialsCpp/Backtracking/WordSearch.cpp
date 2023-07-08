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
void print(vector<vector<char>> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}
void helper(vector<vector<char>> &board, string word, int i, int j, int k, bool &check)
{
    // Base Case
    if (k == word.size())
    {
        check = true;
        return;
    }
    if (i == board.size() or j == board[0].size() or j < 0 or i < 0 or board[i][j] == '9')
        return;
    // Recursive Case
    // 1.Either move to the right and add the character to the string
    if (board[i][j] == word[k])
    {
        char c = board[i][j];
        board[i][j] = '9';
        helper(board, word, i + 1, j, k + 1, check);
        helper(board, word, i, j + 1, k + 1, check);
        helper(board, word, i - 1, j, k + 1, check);
        helper(board, word, i, j - 1, k + 1, check);
        board[i][j] = c;
    }
    return;
}
bool wordSearch(vector<vector<char>> &board, string word)
{
    bool check = false;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == word[0])
                helper(board, word, i, j, 0, check);
        }
    }
    return check;
}
int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << wordSearch(board, word);
    //    print(board);
    return 0;
}
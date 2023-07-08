#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>
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
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return;
}
void traversal(Node *node, int d, map<int, vector<int>> &mapu)
{
    if (node == NULL)
        return;
    mapu[d].push_back(node->data);
    traversal(node->left, d - 1, mapu);
    traversal(node->right, d + 1, mapu);
}
void verticalorderprint(Node *head)
{
    map<int, vector<int>> mapu;
    int d = 0;
    traversal(head, d, mapu);
    for (auto x : mapu)
    {
        int dist = x.first;
        vector<int> line = x.second;
        for (auto y : line)
            cout << y << " ";
        cout << endl;
    }
}
void leftViewUtil(Node *root, vector<int> &view, int level, int &max_level)
{
    if (root == NULL)
        return;
    if (level > max_level)
    {
        view.push_back(root->data);
        max_level = level;
    }
    leftViewUtil(root->left, view, level + 1, max_level);
    leftViewUtil(root->right, view, level + 1, max_level);
}
vector<int> leftView(Node *root)
{
    int max_level = 0;
    vector<int> view;
    leftViewUtil(root, view, 1, max_level);
    return view;
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}
int diameter(Node *root)
{
    if (root == NULL)
        return 0;
}
bool helper(Node *node, int B, vector<int> &result)
{
    if (!node)
        return false;
    result.push_back(node->data);
    if (node->data == B)
        return true;
    if (helper(node->left, B, result))
        return true;
    if (helper(node->right, B, result))
        return true;
    result.pop_back();
    return false;
}
vector<int> solve(Node *A, int B)
{
    vector<int> result;
    helper(A, B, result);
    return result;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    // vector<int> lview = leftView(root);
    // for (auto x : lview)
    //     cout << x << " ";
    // cout << height(root);
    vector<int> result = solve(root, 5);
    for (auto x : result)
        cout << x << " ";
    return 0;
}
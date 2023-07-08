#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <queue>
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
// Input
// 1 2 4 -1 -1 5 7  -1 -1 -1 3  -1 6 -1 -1
class HDPair
{
public:
    int diameter;
    int height;
};
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
Node *buildtree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *n = new Node(d);
    n->left = buildtree();
    n->right = buildtree();
    return n;
}
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
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
            {
                q.push(NULL);
            }
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
Node *buildlevelordertree()
{
    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            current->left = new Node(c1);
            q.push(current->left);
        }
        if (c2 != -1)
        {
            current->right = new Node(c2);
            q.push(current->right);
        }
    }
    return root;
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}
vector<int> printKthLevel(Node *root, int k)
{
    vector<int> ans;
    queue<Node *> q;
    int level = 1;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            level += 1;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (level == k)
            {
                ans.push_back(temp->data);
            }
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}
int sumBT(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int nodeSUm = root->data + sumBT(root->left) + sumBT(root->right);
    return nodeSUm;
}
int diameter(Node *root)
{
    if (root == NULL)
        return 0;
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    return max(D1, max(D2, D3));
}
HDPair OptDiameter(Node *root)
{
    HDPair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }
    HDPair Left = OptDiameter(root->left);
    HDPair Right = OptDiameter(root->right);

    p.height = max(Left.height, Right.height) + 1;
    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;
    p.diameter = max(D1, max(D2, D3));
    return p;
}
int minDepthDFS(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return min(leftDepth, rightDepth) + 1;
}
bool isMirror(Node *root1, Node *root2)
{
    if (root1 == NULL and root2 == NULL)
        return true;
    if (root1 and root2 and root1->data == root2->data)
        return isMirror(root1->left, root2->right) and isMirror(root1->right, root2->left);
    return false;
}
bool isSymmetric(Node *root)
{
    return isMirror(root, root);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->right = new Node(6);
    // root->left->right->left = new Node(7);
    // Node *root = buildlevelordertree();
    cout << "Preorder" << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder" << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(root);
    cout << endl;
    cout << "Level Order" << endl;
    levelorder(root);
    cout << endl;
    // cout << "The height of the tree is " << height(root) << endl;
    // int k = 3;
    // cout << "The " << k << "th level is as follows " << endl;
    // vector<int> kthlevel = printKthLevel(root, k);
    // for (auto x : kthlevel)
    //     cout << x << " ";
    // cout << endl;
    // cout << "The sum of the nodes is " << sumBT(root) << endl;
    // cout << "The diameter of the tree is " << diameter(root) << endl;
    // cout << "The optimised diameter of the tree is " << OptDiameter(root).diameter << endl;
    // cout << "The minimum depth in the tree is " << minDepth(root) << endl;
    cout << "The tree is symmetric :" << isSymmetric(root);
    return 0;
}
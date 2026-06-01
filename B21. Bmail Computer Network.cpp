#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#define endl "\n"
#define MAX 1005
#define ll long long
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int main(void) {
    int n; cin >> n;
    
    vector<int> p(n + 1); // mang luu cac router va vi tri cam cua no tu 2 den n
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }
    
    int cur = n; // khoi tao 1 bien chay qua cac router tu cuoi ve dau
    vector<int> trace; // mang de lu lai duong di nguoc
    while (cur != 1) {
        trace.push_back(cur);
        cur = p[cur]; // truy nguoc ve router duoc ket noi den
    }
    
    reverse(trace.begin(), trace.end());
    
    cout << "1 ";
    for (int x : trace) cout << x << " ";
    cout << endl;
    
    return 0;
}

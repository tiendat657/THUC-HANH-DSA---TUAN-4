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
    
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        int cur = i;
        vector<bool> visited(n + 1, false);
        
        while (!visited[cur]) { // khi ta chua tim duoc ke chu muu
            visited[cur] = true;
            cur = p[cur]; // di tim tiep theo loi ke
        }
        
        cout << cur << " ";
    }
    cout << endl;

    return 0;
}

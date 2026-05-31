#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#define endl "\n"
#define MAX 1005
#define ll long long
using namespace std;

// vi ta co the di chuyen trai phai len xuong va cheo
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};

bool dfs(const vector<string> &g, vector<vector<bool>> &visited, int x, int y, int n) {
    if (x == 1 && y == n - 1) return true; // neu da cham duoc thi tra ve dung va khong de quy nua
    
    visited[x][y] = true; // danh dau da tham
    
    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if (nextX < 2 && nextX >= 0 && nextY <= n - 1 && nextY >= 0) {
            if (g[nextX][nextY] == '0' && !visited[nextX][nextY]) {
                if (dfs(g, visited, nextX, nextY, n)) return true;
            }
        }

    }
    
    // neu ta that bai voi toan bo diem ma ta co the di toi (goi het ma van khong true) -> false
    return false;
}

// ham solve

int main(void) {
    int q; cin >> q;
    
    while (q--) {
        int n; cin >> n;
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        vector<string> g(2); // 0_based (co the lam bang mang 2D bool?)
        
        cin >> g[0] >> g[1]; // string de nhap nhanh chong hon
        
        bool canReach = dfs(g, visited, 0, 0, n);
        
        if (canReach) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}

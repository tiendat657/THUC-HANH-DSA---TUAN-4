====== CACH 1: DSU ======
class DSU {
private:
    vector<int> parent;

public:
    DSU(int n) {
        parent.resize(n);
        
        // iota(dau, cuoi , 0)
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int findSet(int a) {
        if (a == parent[a]) return a;
        return parent[a] = findSet(parent[a]); // path compression
    }
    
    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        
        if (a != b) {
            parent[b] = a;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int)isConnected.size();
        
        int provinces = n; // gia su ban dau chua co bat ki cum nao ca
        DSU dsu(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // vi do thi vo huong -> ma tran doi xung qua duong cheo chinh nen chi can kiem tra tam giac tren la du de gom nhom chung lai (neu thoa)
                // neu 2 dinh co ket noi voi nhau va 2 dinh nay chua duoc xem la 1 cum -> xem la 1 cum (giam 1 don vi + union)
                if (isConnected[i][j] == 1) {
                    if (dsu.findSet(i) != dsu.findSet(j)) {
                        dsu.unionSet(i, j);
                        provinces--;
                    }
                }
            }
        }
        
        return provinces;
    }
};

====== CACH 2: DFS (LOANG) ======
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int city) {
    visited[city] = true; // danh dau da tham roi de khong tham nhieu lam
    
    for (int n = 0; n < (int)isConnected.size(); n++) {
        // neu co duong noi truc tiep va thanh pho ke do chua duoc tham
        if (isConnected[city][n] == 1 && !visited[n]) {
            dfs(isConnected, visited, n); // di tham luon
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = (int)isConnected.size();
    vector<bool> visited(n, false);
    int count = 0; // mac dinh ban dau la 0
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // neu dinh nay chua duoc tham thi ta biet duoc rang dinh nay chua duoc loang toi -> cum khac
            dfs(isConnected, visited, i);
            count++; // tang 1 voi moi cum chua tim thay
        }
    }
    
    return count;
}
};

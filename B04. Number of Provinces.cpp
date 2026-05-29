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

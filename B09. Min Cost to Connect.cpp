struct Edge {
    int u, v, w;
    
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU == rootV) return false;
        
        parent[rootV] = rootU;
        return true;
    }
};

int minCostConnectPoints(vector<vector<int>>& p) {
    int n = (int)p.size();
    vector<Edge> e;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
            
            e.push_back({i, j, d}); // tinh khoang cach giua cac diem
        }
    }
    
    sort(e.begin(), e.end()); // bat dau tu canh co khoang cach nho nhat
    
    DSU dsu(n);
    int minC = 0;
    int eUsed = 0; // cay khung n dinh se co n - 1 canh
    
    for (const auto edge : e) {
        if (dsu.unite(edge.u, edge.v)) {
            minC += edge.w;
            eUsed++;
        }
        
        if (eUsed == n - 1) break;
    }
    
    return minC;
}

    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findSet(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findSet(parent[u]); // Nén đường đi
    }
    
    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        
        if (a == b) {
            return false; // tao chu trinh
        }
        
        parent[b] = a;
        return true;
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = (int)edges.size();
    DSU dsu(n);
    
    
    for (const auto &e : edges) {
        int u = e[0];
        int v = e[1];
        
        if (!dsu.unionSet(u, v)) { // neu nhu trong 1 do thi con lien thong ma co them 1 canh noi 2 dinh nua thi chac chan se bi thua
            return e;
        }
    }
    
    return {};
}

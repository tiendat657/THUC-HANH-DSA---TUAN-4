class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        
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
            if (rank[a] < rank[b]) {
                parent[a] = b;
            } else if (rank[a] > rank[b]) {
                parent[b] = a;
            } else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        
        for (const auto & edge : edges) {
            int a = edge[0];
            int b = edge[1];
            
            dsu.unionSet(a, b);
        }
        
        return dsu.findSet(source) == dsu.findSet(destination);
    }
};

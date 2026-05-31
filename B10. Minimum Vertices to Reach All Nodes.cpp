vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<bool> hasIncomingEdge(n, false);
    for (const auto &edge: edges) {
        int to = edge[1];
        hasIncomingEdge[to] = true;
    }
    
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (!hasIncomingEdge[i]) {
            res.push_back(i);
        }
    }
    
    return res;
}

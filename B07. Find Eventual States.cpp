bool dfs(vector<vector<int>> &a, vector<int> &state, int node) {
    if (state[node] == 1) return false; // co chu trinh
    if (state[node] == 2) return true; // node nay da an toan tu truoc
    
    state[node] = 1; // danh dau rang node nay da duoc duyet
    
    for (int v : a[node]) {
        if (!dfs(a, state, v)) { // neu co bat ki nhanh nao dan den khong an toan
            return false;
        }
    }
    
    state[node] = 2; // duyet het cac node va an toan
    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = (int)graph.size();
    vector<int> res;
    vector<int> state(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        if (dfs(graph, state, i)) { // kiem tra tat ca cac canh cua do thi
            res.push_back(i);
        }
    }
    
    return res;
}

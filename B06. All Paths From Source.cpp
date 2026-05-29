void dfs(vector<vector<int>> &graph, vector<int> &curPath, vector<vector<int>> &ans, int cur, int des) {
    if (cur == des) {
        ans.push_back(curPath);
        return; // ta da tim duoc -> quay lui
    }
    
    for (int next : graph[cur]) {
        curPath.push_back(next);
        
        dfs(graph, curPath, ans, next, des);
        
        curPath.pop_back(); // ta thu tim duong khac bang cach bo 1 phan duong cu di
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = (int)graph.size();
    vector<int> curPath;
    vector<vector<int>> ans;
    
    curPath.push_back(0); // ta bat dau tu dinh 0
    
    dfs(graph, curPath, ans, 0, n - 1);
    
    return ans;
}

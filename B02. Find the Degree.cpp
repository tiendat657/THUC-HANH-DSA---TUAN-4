vector<int> findDegrees(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    vector<int> res(n, 0);
    
    for (int i = 0; i < n; i++) {
        int cur = 0;
        
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) cur++;
        }
        
        res[i] = cur;
    }
    
    return res;
}

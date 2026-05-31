int findChampion(int n, vector<vector<int>>& edges) {
    vector<bool> hasIncomingNode(n, false);
    
    for (const auto &e : edges) {
        int to = e[1];
        hasIncomingNode[to] = true;
    }
    
    int count = 0, winner = -1;
    for (int i = 0; i < n; i++) {
        if (!hasIncomingNode[i]) {
            winner = i;
            count++;
        }
    }
    
    if (count != 1) return -1;
    return winner;
}

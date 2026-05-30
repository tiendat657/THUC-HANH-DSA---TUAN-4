bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = (int)rooms.size();
    
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    q.push(0);
    visited[0] = true;
    int count = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (count == n) return true;
        
        for (int v : rooms[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                count++;
            }
        }

    }
    
    return count == n;
}

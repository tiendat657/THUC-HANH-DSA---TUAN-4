void dfs(vector<vector<int>> &a, vector<bool> &visited, int &e, int &v, int u) {
    v++; // thay 1 dinh moi voi moi lan goi de quy toi dinh duoc xet hien tai
    e += (int)a[u].size(); // cong vao so canh ma dinh nay noi toi vao tong so canh
    visited[u] = true;
    
    for (int next : a[u]) {
        if (!visited[next]) {
            dfs(a, visited, e, v, next); // loang tiep de cho ra duoc 1 do thi hoan chinh voi so canh e va so dinh v
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>> &edges) {
    // mot do thi con duoc xem nhu hoan hao neu no co so dinh dung bang v * (v - 1) / 2
    // ta phai chuyen sang danh sach ke de dem so canh de dang hon
    vector<vector<int>> a(n + 1);
    for (const auto & edge : edges) {
        a[edge[0]].push_back(edge[1]);
        a[edge[1]].push_back(edge[0]); // do thi vo huong
    }
    
    vector<bool> visited(n + 1);
    int cmp = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // ta se khong kiem tra 1 dinh neu no da nam trong 1 do thi con khac -> tranh tang component vo nghia
            int e = 0, v = 0; // chuan bi de kiem tra xem e = v * (v - 1) / 2 co dung khong
            
            dfs(a, visited, e, v, i); // loang tat ca cac dinh
            
            e /= 2; // vi do thi vo huong -> moi dinh ket noi 2 chieu nen phai giam di 1 chieu
            
            if (e == v * (v - 1) / 2) cmp++; // neu do thi con la hoan hao
        }

    }
    
    return cmp;
}

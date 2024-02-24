vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
    vector <int> indeg(V, 0);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indeg[adj[i][j]]++;
        }
    }
    
    queue <int> q;
    vector <int> ans;
    for (int i = 0; i < V; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            ans.push_back(i);
        }
    }
    
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for (int i = 0; i < adj[curr].size(); i++) {
            int adjNode = adj[curr][i];
            indeg[adjNode]--;
            if (indeg[adjNode] == 0) {
                q.push(adjNode);
                ans.push_back(adjNode);
            }
        }
    }
    
    return ans;
}
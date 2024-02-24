void DFS (int node, vector <int>& ans, vector <int>& vis, vector <int> adj[]) {
    vis[node] = 1;
    for (int adjNode : adj[node]) {
        if (!vis[adjNode]) {
            DFS(adjNode, ans, vis, adj);
        }
    }
    ans.push_back(node);
}
	
vector<int> topoSort(int V, vector<int> adj[]) {
    vector <int> vis (V, 0);
    vector <int> ans;
    for (int i = 0; i < V; i++) {
        if (!vis[i])
            DFS(i, ans, vis, adj);
    }
 
    reverse(ans.begin(), ans.end());
    return ans;
}
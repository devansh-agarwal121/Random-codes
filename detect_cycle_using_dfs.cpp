bool dfs (int node, vector <int>& vis, vector <int>& pathVis, vector <int> adj[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (int adjNode : adj[node]) {
        if (!vis[adjNode]) {
            if (dfs(adjNode, vis, pathVis, adj)) return true;
        }
        else {
            if (pathVis[adjNode]) return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

  
bool isCyclic(int V, vector<int> adj[]) {
    vector <int> vis (V, 0);
    vector <int> pathVis (V, 0);
    
    for (int i = 0; i < V; i++) {
        if (!vis[i])
            if(dfs(i, vis, pathVis, adj)) return true;
    }
    
    return false;
}
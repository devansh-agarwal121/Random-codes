#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class T1, class T2, class T3>
vector <int> lexicTopo (int& V, vector <int> indeg, vector < vector <int> >& adj) {
    
    vector <int> ans;
    priority_queue <T1, T2, T3> heap; 
    for (int i = 0;  i < V; i++) {
        if (indeg[i] == 0) {
            heap.push(i);
        }
    }
    
    while (!heap.empty()) {
        int curr = heap.top(); heap.pop();
        ans.push_back(curr);
        for (int adjNode : adj[curr]) {
            indeg[adjNode]--;
            if (indeg[adjNode] == 0) {
                heap.push(adjNode);
            }
        }
    }

    // if (ans.size() != V) return {-1}; // to check cycle
    return ans;
}

int main () {

    int V, E;
    cin >> V >> E;
    vector < vector <int> > adj(V, vector <int>());
    for (int i = 0; i < E; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    
    vector <int> indeg (V, 0);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indeg[adj[i][j]]++;
        }
    }
    
    vector <int> lexSmall = lexicTopo<int, vector<int>, greater<int> >(V, indeg, adj);
    vector <int> lexLarge = lexicTopo<int, vector <int>, less <int> >(V, indeg, adj);

    for (int i : lexSmall) cout << i << " ";
        cout << endl;
    for (int i : lexLarge) cout << i << " ";
        cout << endl;

    return 0;
}

/* 
    Example TC:
        i/p:    6 6
                5 2
                5 0
                4 0
                4 1
                2 3
                3 1
        o/p:    4 5 0 2 3 1 
                5 4 2 3 1 0


*/





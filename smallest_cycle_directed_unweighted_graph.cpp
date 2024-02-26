#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Given an event dependency network, where each node depicts the event di, your task is to 
    generate the lexicographically, i)smallest possible &ii)largest possible valid events sequencing schedules. 
    If it's impossible to find them out, compute the size of the smallest possible cyclic dependency in the input event dependency network.
    
    Link: https://www.hackerrank.com/contests/daa24-mockcontest2/challenges/the-quark2k23-schedule/problem
*/


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

    if (ans.size() != V) return {-1};
    return ans;
}

void dfs (int node, vector <pair <int, int> >& vis, vector < vector <int> >& adj, int &currSize) {
    for(int i=0; i<adj[node].size(); i++){
        int adjNode = adj[node][i];
        if(vis[adjNode].first == -1){
            vis[adjNode] = {vis[node].first + 1, vis[node].second};
            dfs(adjNode, vis, adj, currSize);
        }
        else if(vis[adjNode].second == vis[node].second){
            currSize = min(currSize, vis[node].first - vis[adjNode].first + 1); 
            // vis[node].first == distance from the greatest grandparent (for whom dfs was initially called), similarly for adjNode. +1 for the last edge
        }
    }
    vis[node].second = -1; // to reinitialise main parent back to -1.
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
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
    
    if (lexSmall[0] == -1) {
        int minCycle = INT_MAX;
        vector <pair <int, int> > vis (V, {-1, -1});
        for (int i = 0; i < V; i++) {
            if (vis[i].first == -1) {
                int currSize = INT_MAX;
                vis[i] = {0, i};
                dfs (i, vis, adj, currSize);
                minCycle = min(minCycle, currSize);
            }
        }
        cout << minCycle;
    }
    else {
        for (int i : lexSmall) cout << i << " ";
        cout << endl;
        for (int i : lexLarge) cout << i << " ";
    }
    
    return 0;
}


/* Example TC1 (no cycle):
        i/p:    6 6
                5 2
                5 0
                4 0
                4 1
                2 3
                3 1
        o/p:    4 5 0 2 3 1 
                5 4 2 3 1 0

    Example TC2 (2 cycles present):
        i/p:    9 11
                5 2
                5 0
                4 0
                4 1
                2 3
                3 1
                1 6
                6 7
                7 8
                8 1
                3 5
        o/p:    3
*/

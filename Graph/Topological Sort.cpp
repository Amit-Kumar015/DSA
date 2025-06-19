// https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// kahn algorithm 
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> indegree(v, 0);
    unordered_map<int, list<int>> adj;

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);

        // find all indegree
        indegree[v]++;
    }

    vector<int> ans;
    queue<int> q;
            
    for(int i=0; i<v; i++){
        // push node whose indegree is 0 in queue 
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // do bfs
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto neighbour: adj[frontNode]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}


// using dfs
#include <bits/stdc++.h> 
void topoSort(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited,
        stack<int> &s){
            visited[node] = 1;

            for(auto neighbour: adj[node]){
                if(!visited[neighbour]){
                    topoSort(neighbour, adj, visited, s);
                }
            }
            s.push(node);
        }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> s;
    vector<bool> visited(v);
    for(int i=0; i<v; i++){
        if(!visited[i]){
            topoSort(i, adj, visited, s);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
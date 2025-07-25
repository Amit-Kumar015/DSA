// https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

void dfs(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited,
    vector<int>& component, int node){

    component.push_back(node);
    visited[node] = 1;

    // traversasl for all neighbours of node
    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(adj, visited, component, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prepare adjList
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // ans is storing dfs traversal of diff components
    vector<vector<int>> ans;
    unordered_map<int, bool> visited; 

    for(int i=0; i<V; i++){
        if(!visited[i]){
            // using component vector to store each component dfs traversal
            vector<int> component;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}
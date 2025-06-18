// https://www.naukri.com/code360/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool>& visited, vector<int>& ans,  int node){

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // storing the node in ans
        ans.push_back(frontNode);

        // traversing for neighbours of front node
        for(auto i: adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void prepareAdj(unordered_map<int, list<int>> &adj, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

vector<int> bfsTraversal(int vertex, vector<pair<int, int>> edges){
    unordered_map<int, bool> visited;
    vector<int> ans;

    unordered_map<int, list<int>> adj;

    // stores in sorted order
    // unordered_map<int, set<int>> adj;

    prepareAdj(adj, edges);

    // loop for disconnected nodes
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bfs(adj, visited, ans, i);
        }
    }

    return ans;
}
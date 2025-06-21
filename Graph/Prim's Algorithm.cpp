int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    vector<bool> visited(V, 0);
    vector<pair<int, int>> mst;
    // {weight, node, parent}
    pq.push({0, 0, -1});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int w = it[0];
        int node = it[1];
        int parent = it[2];

        // add to mst
        if(visited[node]) continue;
        visited[node] = 1;

        // first node
        if(parent != -1){
            mst.push_back({parent, node});
        }

        for(auto it: adj[node]){
            int adjNod = it[0];
            int w = it[1];
            if(!visited[adjNod]){
                pq.push({w, adjNod, node});
            }
        }
    }
}
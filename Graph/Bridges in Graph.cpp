void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, 
    vector<vector<int>> &result, unordered_map<int, list<int>> adj, vector<int> &vis){
        vis[node] = 1;
        disc[node] = low[node] = timer++;

        for(auto nbr: adj[node]){
            if(nbr == parent) continue;
            if(!vis[nbr]){
                dfs(nbr, node, timer, disc, low, result, adj, vis);
                low[node] = min(low[node], low[nbr]);

                // check bridge
                if(low[nbr] > disc[node]){
                    result.push_back({node, nbr});
                }
            }
            else{
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    vector<int> vis(v, 0);

    vector<vector<int>> result;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}
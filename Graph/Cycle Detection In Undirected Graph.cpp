// https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// using bfs
bool isCyclic(int src, unordered_map<int , list<int>> &adj,
        unordered_map<int, bool> &visited){
            queue<int, int> q;
            q.push({src, -1});
            visited[src] = 1;

            while(!q.empty()){
                int frontNode = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto neighbour: adj[frontNode]){
                    if(visited[neighbour] && neighbour != parent){
                        return true;
                    }
                    else if(!visited[neighbour]){
                        q.push({neighbour, frontNode});
                        visited[neighbour] = 1;
                    }
                }
            }
            return false;
        }

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int , list<int>> adj;
    // making adj list
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    // visiting all components
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(isCyclicBFS(i, adj, visited)){
                return "Yes";
            }
        }
    }

    return "No";
}

// using dfs
bool isCyclicDFS(int src, int parent, unordered_map<int , list<int>> &adj,
        unordered_map<int, bool> &visited){
            visited[src] = 1;

            for(auto neighbour: adj[src]){
                if(!visited[neighbour]){
                    if(isCyclicDFS(neighbour, src, adj, visited)){
                        return true;
                    }
                }
                else if(neighbour != parent){
                    return true;
                }
            }

            return false;
        }

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int , list<int>> adj;
    // making adj list
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    // visiting all components
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(isCyclicDFS(i, -1, adj, visited)){
                return "Yes";
            }
        }
    }

    return "No";
}


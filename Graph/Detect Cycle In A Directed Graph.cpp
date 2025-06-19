// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// using bfs
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> indegree(n, 0);
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);

        indegree[v]++;
    }

    queue<int> q;
    int cnt =0;
            
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // keep track of no of nodes processed
        cnt++;

        for(auto neighbour: adj[frontNode]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    // cnt == n means correct topological sort, no cycle
    if(cnt == n){
        return false;
    }
    else{
        return true;
    }
}

// using dfs
bool checkCycle(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,
        unordered_map<int, bool> &dfsVisited){
            visited[node] = 1;
            // recursion call visited node
            dfsVisited[node] = 1;

            for(auto neighbour: adj[node]){
                if(!visited[neighbour]){
                    bool cycleDetected = checkCycle(neighbour, adj, visited, dfsVisited);
                    if(cycleDetected){
                        return true;
                    }    
                }
                // if both visited and dfsVisited is true for a node, cycle present
                else if(dfsVisited[neighbour]){
                    return true;
                }
            }
            // after recursion call mark dfsVisited false
            dfsVisited[node] = 0;

            return false;
        }

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int>> adj;
  for(int i=0; i<edges.size(); i++){
      int u = edges[i].first;
      int v = edges[i].second;

      adj[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;
  for(int i=1; i<n; i++){
      if(!visited[i]){
          if(checkCycle(i, adj, visited, dfsVisited)){
              return true;
          }
      }
  }

  return false;
}
void makeSet(vector<int> &parent, vector<int> &rank, int n){
    // initialization
  for(int i=0; i<n; i++){
    rank[i] = 0;
    parent[i] = i;
  }
}

int findParent(vector<int> &parent, int node){
    // cond for parent
  if(parent[node] == node){
    return node;
  }
  // path compression
  return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u] < rank[v]){
    parent[u] = v;
  }
  else if(rank[u] > rank[v]){
    parent[v] = u;
  }
  else{
    parent[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int> rank(n);
  vector<int> parent(n);
  makeSet(parent, rank, n);

  vector<pair<int, pair<int, int>>> edge;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];
    edge.push_back({w, {u, v}});
  }

  sort(edge.begin(), edge.end());
  int mstWt=0;
  for(auto it: edge){
    int wt = it.first;
    int u = it.second.first;
    int v = it.second.second;

    if(findParent(u) != findParent(v)){
      mstWt += wt;
      unionSet(u, v, parent, rank);
    }
  }

  return mstWt;
}
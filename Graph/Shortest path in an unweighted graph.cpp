// https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// using bfs
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, list<int>> adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;

	queue<int> q;
	q.push(s);
	visited[s] = 1;
	parent[s] = -1;

	while(!q.empty()){
		int frontNode = q.front();
		q.pop();

		for(auto neighbour: adj[frontNode]){
			if(!visited[neighbour]){
				q.push(neighbour);
				visited[neighbour] = 1;
				parent[neighbour] = frontNode;
			}
		}
	}

	vector<int> ans;
	int currentNode = t;
	ans.push_back(currentNode);
	while(currentNode != s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

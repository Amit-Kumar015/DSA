// https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// only works for positive weight edges
// using set
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // undirected graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // set on basis {dist, node}
    set<pair<int, int>> s;
    // intialized dist to each node with max
    vector<int> dist(vertices, INT_MAX);

    dist[source] = 0;
    // {dist, node}
    s.insert({0, source});

    while(!s.empty()){
        // fetch top record
        auto top = *(s.begin());
        int distNode = top.first;
        int topNode = top.second;

        // erase top record
        s.erase(s.begin());

        for(auto i: adj[topNode]){
            if(distNode + i.second < dist[i.first]){
                // find already present node
                auto record = s.find({dist[i.first], i.first});

                // if present erase it
                if(record != s.end()){
                    s.erase(record);
                }

                // distance update
                dist[i.first] = distNode + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }

    return dist;
}

// using priority queue
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // undirected graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // priority_queue on basis {dist, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // intialized dist to each node with max
    vector<int> dist(vertices, INT_MAX);

    dist[source] = 0;
    // {dist, node}
    pq.push({0, source});

    while(!pq.empty()){
        // fetch top record
        auto top = pq.top();
        int distNode = top.first;
        int topNode = top.second;

        // erase top record
        pq.pop();

        for(auto i: adj[topNode]){
            if(distNode + i.second < dist[i.first]){

                // distance update
                dist[i.first] = distNode + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }

    return dist;
}

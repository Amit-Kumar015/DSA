#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// using 2d matrix

class graph{
    public:
        // dynamic 2d array
        int ** arr;
        int size;

        graph(int m){
            size = m;
            arr = new int *[size];

            for(int i=0; i<size; i++){
                arr[i] = new int [size];
                for(int j=0; j<size; j++){
                    // initialize with 0
                    arr[i][j] = 0;
                }
            }
        }

        void addEdges(int u, int v, int direction){
            arr[u][v] = 1;

            if(!direction){
                arr[v][u] = 1;
            }
        }

        void print(){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    cout<< arr[i][j] << " ";
                }
                cout<<endl;
            }
        }
}

// using graph
class graph{
    public:
        unordered_map<int, list<int>> adj;

        void addEdges(int u, int v, int direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed

            adj[u].push_back(v);

            if(!direction){
                adj[v].push_back(u);
            }
        }

        void print(){
            for(auto i : adj){
                cout<< i.first << " -> ";
                for(auto j : i.second){
                    cout<< j << ", ";
                }
                cout<<endl;
            }
        }

};

int main(){
    int n;
    cout<<"enter the number of nodes "<<endl;
    cin>>n;

    int m ;
    cout<< "enter the number of edges "<<endl;
    cin>>m;

    graph g;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u >> v;

        g.addEdges(u, v, 0);
    }

    g.print();
    
    return 0;
}

// using vector

// https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int> ans[n];

    // ans array will store all adjacent nodes corresponding on indexes
    for(int i=0; i<m; i++){
        int u= edges[i][0];
        int v= edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);

        // entering adjacent nodes
        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}
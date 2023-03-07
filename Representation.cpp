#include<iostream>
#include<vector>
using namespace std;

int main(){

    //Representation for adjacency martrix for undirected graph
    // time complexity o(n)
    //space on(n*n)

    int n , m;
    cin>>n>>m;
    

    int adj[n+1][n+1];

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;  // this statement will we remove in the case of directed  graph
    }


    // for adjacency list for undirected graph

    //SPACE COMPLEXITY 2(E) BECASUE THEY STORE THE TWICES OF EDGES BUT IN THE CASE OF DIRECTED GRAPH IT WILL BECOME (E)

    vector<int> adj[n+1];
    for(int i = 0 ; i<m; i++){
        int u , v;
        cin>>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // THIS LINE REMOVE AT THE TIME OF DIRECTED GRAPGH

    }

    // AT THE TIME OF WAITED GRAPH WE USE PAIR INSIDE THE VECTOR

    vector<pair<int,int>>ad[n+1]; // THIS STORE THE NODE ANS WEIGHT OF THE NODE ALSO
}
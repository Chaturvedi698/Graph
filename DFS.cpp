#include<bits/stdc++.h>
using namespace std;

class solution{
    private:
    void depth(int node,vector<int>&list,vector<int>adj[],int visited[]){
        // if(visited[node]) return;
        visited[node] = 1;
        list.push_back(node);
        // traverse all its neighbours
        for(auto it:adj[node]){
            // if the neighbour is not visited
            if(!visited[it])
                depth(it,list,adj,visited);
            
        }
    }
    public:
    vector<int> dfs(int v, vector<int>adj[]){
        int start = 1;
        int visited[v]={0};
        // create a list to store dfs
        vector<int>list;
        visited[1] = 1;
        // call dfs for starting node
        depth(start,list,adj,visited);
        return list;
    }
};

void addEdge(vector<int>adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int>ans){
    for(auto it:ans){
        cout<<it<<" ";
    }
}


int main(){

   vector<int>adj[9];

    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,5);
    addEdge(adj,2,6);
    addEdge(adj,3,4);
    addEdge(adj,3,7);
    addEdge(adj,4,8);
    addEdge(adj,7,8);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 2, 4);
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 3);

    solution obj;
    
    vector<int> ans = obj.dfs(9,adj);
    print(ans);

    return 0;
    
}

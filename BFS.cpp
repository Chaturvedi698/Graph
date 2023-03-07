#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:


    vector<int> bfsofgraph(int v, vector<int>adj[]){
        int visited[v] ={0};
        visited[0] = 1;

        queue<int>q;
        q.push(0);

        vector<int>bfs;


        while(!q.empty()){
            int node = q.front();
            q.pop();

            bfs.push_back(node);

            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it] =1;
                    q.push(it);
                }
            }
        }


        return bfs;




    }
};

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int>ans){
    for(auto it:ans){
        cout<<it<<" ";
    }
}
int main(){

vector<int> adj[5];
 
addEdge(adj, 0, 1);
addEdge(adj, 1, 2);
addEdge(adj, 1, 3);
addEdge(adj, 0, 4);

Solution obj;
vector<int>ans = obj.bfsofgraph(5,adj);

print(ans);

return 0;
}
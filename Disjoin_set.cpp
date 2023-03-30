#include<bits/stdc++.h>
using namespace std;


class Disjoint{
    public:
    vector<int>parent,rank,size;
    Disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1,0); // initially all nodes rank are 0 becuase no node are connected
        size.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i; // making all nodes self parent  becuase no node are connected
            size[i] = 1;   // making all nodes size is 1 because initially no one is connect and the size is 1 due to self node
        }
    }

    int Findparent(int node){
        if(node == parent[node]) return node;

        return parent[node] = Findparent(parent[node]);  // here we do a path comprensiion 
    }

    void UnionRank(int u, int v){
        int upu = Findparent(u);
        int upv = Findparent(v);
        if(upu==upv) return;   // if both parent are same no need to join them

        if(rank[upu]<rank[upv]){       
            //   Here we join smaller rank into large rank , it have a better complexity because 
            // large rank take more time to find parent but small rank take less time to find parent
            parent[upu] = upv;
        }
        else if(rank[upv]<rank[upu]){
            parent[upv] = upu;
        }
        else{   // if both are same rank then we join anyone to each other and increment joined rank
            parent[upv] = upu;
            rank[upu]++;
        }
    }


    void UnionSize(int u, int v){
        int upu = Findparent(u);
        int upv = Findparent(v);
        if(upu==upv) return;

        if(size[upu]<size[upv]){
            parent[upu] = upv;
            size[upv] += size[upu];    
         }
         else{
            parent[upv] = upu;
            size[upu] += size[upv];
         }
    }




};

int main(){

    Disjoint ds(7);
    ds.UnionSize(1, 2);
    ds.UnionSize(2, 3);
    ds.UnionSize(4, 5);
    ds.UnionSize(6, 7);
    ds.UnionSize(5, 6);
    ds.UnionRank(3, 7);


    return 0;
}
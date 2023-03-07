#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[]) {
// aagr visited aaray  mai bus 1 hai to iska mtlb hai ki vo visited hai but uss path mai nhi hai or aagr 2 hai to visited bhi hai or path mai bhi hai 

		vis[node] = 2; // 2 means for 1 for visited and 1 for the same path 
		
		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis) == true)
					return true;
			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (vis[it]==2) { // aagr visited hai or hum ussi path mai hai to iska mtlb yahi hai ki hum cycle mai hai 
				return true;
			}
		}

		vis[node] = 1;  // we again make vis 1 kyunki humne vo same path cover kr liya hai
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis) == true) return true;
			}
		}
		return false;
	}
};


int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}
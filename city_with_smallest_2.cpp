//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges,
                 int distanceThreshold)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int mincity, city = 1e9;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < n; i++)
        {
            vector<int> dist(n, 1e9);
            dist[i] = 0;
            q.push({i, 0});

            while (!q.empty())
            {
                int node = q.top().first;
                int dis = q.top().second;
                q.pop();

                for (auto it : adj[node])
                {
                    int adjnode = it.first;
                    int adjwt = it.second;
                    if (dis + adjwt < dist[adjnode])
                    {
                        dist[adjnode] = dis + adjwt;
                        q.push({adjnode, dist[adjnode]});
                    }
                }
            }

            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            if (cnt <= mincity)
            {
                mincity = cnt;
                city = i;
            }
        }
        return city;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
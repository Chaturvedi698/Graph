// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int MinimumEffort(vector<vector<int>> &heights)
//     {

//         // Create a priority queue containing pairs of cells
//         // and their respective distance from the source cell in the
//         // form {diff, {row of cell, col of cell}}.
//         priority_queue<pair<int, pair<int, int>>,
//                        vector<pair<int, pair<int, int>>>,
//                        greater<pair<int, pair<int, int>>>>
//             pq;

//         int n = heights.size();
//         int m = heights[0].size();

//         // Create a distance matrix with initially all the cells marked as
//         // unvisited and the dist for source cell (0,0) as 0.
//         vector<vector<int>> dist(n, vector<int>(m, 1e9));
//         dist[0][0] = 0;
//         pq.push({0, {0, 0}});

//         // The following delta rows and delts columns array are created such that
//         // each index represents each adjacent node that a cell may have
//         // in a direction.
//         int dr[] = {-1, 0, 1, 0};
//         int dc[] = {0, 1, 0, -1};

//         // Iterate through the matrix by popping the elements out of the queue
//         // and pushing whenever a shorter distance to a cell is found.
//         while (!pq.empty())
//         {
//             auto it = pq.top();
//             pq.pop();
//             int diff = it.first;
//             int row = it.second.first;
//             int col = it.second.second;

//             // Check if we have reached the destination cell,
//             // return the current value of difference (which will be min).
//             if (row == n - 1 && col == m - 1)
//                 return diff;

//             for (int i = 0; i < 4; i++)
//             {
//                 // row - 1, col
//                 // row, col + 1
//                 // row - 1, col
//                 // row, col - 1
//                 int newr = row + dr[i];
//                 int newc = col + dc[i];

//                 // Checking validity of the cell.
//                 if (newr >= 0 && newc >= 0 && newr < n && newc < m)
//                 {
//                     // Effort can be calculated as the max value of differences
//                     // between the heights of the node and its adjacent nodes.
//                     int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

//                     // If the calculated effort is less than the prev value
//                     // we update as we need the min effort.
//                     if (newEffort < dist[newr][newc])
//                     {
//                         dist[newr][newc] = newEffort;
//                         pq.push({newEffort, {newr, newc}});
//                     }
//                 }
//             }
//         }
//         return 0; // if unreachable
//     }
// };

// int main()
// {
//     // Driver Code.

//     vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

//     Solution obj;

//     int ans = obj.MinimumEffort(heights);

//     cout << ans;
//     cout << endl;

//     return 0;
// }

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 2, m = 3, x = 2, y = 3;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    vec[x-1][y-1] = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int cnt = 0;
    queue<pair<int, int>> pq;
    pq.push({x-1, y-1});
    while (!pq.empty())
    {
        int qsize = pq.size();
        while(qsize--){
        int row = pq.front().first;
        int col = pq.front().second;
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vec[nrow][ncol] == 0)
            {
                vec[nrow][ncol] = 1;
                pq.push({nrow, ncol});
                // cout<<cnt;
                
            }
        }
        }
        // cnt++;
    
    }
    cout << cnt;
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     for (int j = 0; j < vec[0].size(); j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}

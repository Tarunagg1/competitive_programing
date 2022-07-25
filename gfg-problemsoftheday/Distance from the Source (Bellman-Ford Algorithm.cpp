// Distance from the Source (Bellman-Ford Algorithm)
// MediumAccuracy: 50.02%Submissions: 11765Points: 4
// Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
// Note: The Graph doesn't contain any negative weight cycle.
 

// Example 1:

// Input:

// E = [[0,1,9]]
// S = 0
// Output:
// 0 9
// Explanation:
// Shortest distance of all nodes from
// source is printed.
// Example 2:

// Input:

// E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
// S = 2
// Output:
// 1 6 0
// Explanation:
// For nodes 2 to 0, we can follow the path-
// 2-0. This has a distance of 1.
// For nodes 2 to 1, we cam follow the path-
// 2-0-1, which has a distance of 1+5 = 6,
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function bellman_ford()  which takes a number of vertices V and an E-sized list of lists of three integers where the three integers are u,v, and w; denoting there's an edge from u to v, which has a weight of w as input parameters and returns a list of integers where the ith integer denotes the distance of an ith node from the source node. If some node isn't possible to visit, then its distance should be 100000000(1e8).

 

// Expected Time Complexity: O(V*E).
// Expected Auxiliary Space: O(V).

 

// Constraints:
// 1 ≤ V ≤ 500
// 1 ≤ E ≤ V*(V-1)
// -1000 ≤ adj[i][j] ≤ 1000
// 0 ≤ S < V




class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
         vector<int> dp(V, 100000000);
        dp[S] = 0;
        for(int i = 0; i < V; i++){
            for(int j = 0; j < adj.size(); j++){
                if(dp[adj[j][0]] != 100000000){
                    dp[adj[j][1]] = min(dp[adj[j][1]], dp[adj[j][0]] + adj[j][2]);
                }
            }
        }
        return dp;
    }
};

































// Eulerian Path in an Undirected Graph 
// Easy Accuracy: 67.21% Submissions: 2194 Points: 2
// Given an adjacency matrix representation of an unweighted undirected graph named graph, which has N vertices. You have to find out if there is an eulerian path present in the graph or not.
// Note: The graph consists of a single component

// Example 1:

// Input: N = 5
// graph = {{0, 1, 0, 0, 1}, 
//          {1, 0, 1, 1, 0}, 
//          {0, 1, 0, 1, 0}, 
//          {0, 1, 1, 0, 0}, 
//          {1, 0, 0, 0, 0}}
// Output: 1
// Explaination: There is an eulerian path. 
// The path is 5->1->2->4->3->2.
// Example 2:

// Input: N = 5
// graph = {{0, 1, 0, 1, 1}, 
//          {1, 0, 1, 0, 1}, 
//          {0, 1, 0, 1, 1}, 
//          {1, 1, 1, 0, 0}, 
//          {1, 0, 1, 0, 0}}
// Output: 0
// Explaination: There is no eulerian path in 
// the graph.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function eulerPath() which takes N and graph as input parameters and returns 1 if there is an eulerian path. Otherwise returns 0.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ N ≤ 50 






class Solution{
public:
    int eulerPath(int N, vector<vector<int>> graph){
        // code here
        int cnt = 0;
       for(int i=0; i<N; i++) {
           int val = 0;
           for(int j=0; j<N; j++) {
               val += graph[i][j];
           }
           if(val & 1) cnt += 1;
       }
       return (cnt == 2);
    }
};
// Number of Provinces
// MediumAccuracy: 43.29%Submissions: 8226Points: 4
// Given a graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.
// Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

 

// Example 1:

// Input:
// [
//  [1, 0, 1],
//  [0, 1, 0],
//  [1, 0, 1]
// ]

// Output:
// 2
// Explanation:
// The graph clearly has 2 Provinces [1,3] and [2]. 
// As city 1 and city 3 has a path between them they 
// belong to a single province. City 2 has no path 
// to city 1 or city 3 hence it belongs to another 
// province.
// Example 2:
// Input:
// [
//  [1, 1],
//  [1, 1]
// ]

// Output :
// 1

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.


// Expected Time Complexity: O(V2)
// Expected Auxiliary Space: O(V)


// Constraints:
// 1 ≤ V ≤ 500



class Solution {
  public:
    
    void DFs(vector<int>adj[],int s,vector<bool>&visited){
      visited[s]=true;
      for(int u:adj[s]){
          if(visited[u]==false){
              DFs(adj,u,visited);
          }
      }
  }
  
   int numProvinces(vector<vector<int>> adj, int V) {
       // code here

       //we convert into array of vector // 
       vector<int>graph[V];
       for(int i=0;i<adj.size();i++){
           for(int j=0;j<adj.size();j++){
               if(adj[i][j]){
                   graph[i].push_back(j);
                   graph[j].push_back(i);
               }
           }
       }
       int count=0;

       //we declare visited vector
       vector<bool>visited(V,0);
       for(int i=0;i<V;i++){
           if(visited[i]==false){
               DFs(graph,i,visited);
               count++;
           }
       }
       return count;
   }
   
};





































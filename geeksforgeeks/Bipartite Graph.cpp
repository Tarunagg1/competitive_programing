// Bipartite Graph 
// Medium Accuracy: 40.1% Submissions: 66294 Points: 4
// Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

// Example 1:

// Input: 

// Output: 1
// Explanation: The given graph can be colored 
// in two colors so, it is a bipartite graph.
// Example 2:

// Input:

// Output: 0
// Explanation: The given graph cannot be colored 
// in two colors such that color of adjacent 
// vertices differs. 
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
 

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105

// View Bookmarked Problems





class Solution {
public:
 bool check(int curr,vector<int>adj[], vector<int>& col){
        queue<int> q;
	    q.push(curr);
	    col[curr]=1;
	    while(!q.empty()){
            int node=q.front();
	        q.pop();
	        for(auto it:adj[node]){
	            if(col[it]==-1){
	                col[it]=!col[node];
	                q.push(it);
	            }
	            else{
	                if(col[it]==col[node]) return false;
	            }
            }
	    }
	    return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	       vector<int> col(n,-1);
	    for(int i=0;i<n;i++){
	        if(col[i]==-1) 
	            if(check(i,adj,col)==false) return false;
	    }
	    return true;
	}

};















































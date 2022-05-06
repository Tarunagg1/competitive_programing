// Kill Captain America 
// Hard Accuracy: 67.31% Submissions: 893 Points: 8
// Captain America is hiding from Thanos in a maze full of rooms.
// The maze is designed in such a way that the room, within it, leads to another room via gate. Captain America is hiding only in those rooms which are accessible directly/indirectly through every other room in the maze.
// Further provided that, the movement from one room (R1) to another room (R2) is one way(unidirectional) only .
// Now, you being on Thanos side, want to kill Captain America.  

 

// Example 1:

// Input:
// N = 5 and M =5
// V = [[1, 2], [2, 3], [3, 4], [4, 3], [5, 4]]
// Output: 2
// Explanation:
// We can look closesly after forming graph 
// than captain america only can hide in a 
// room 3 and 4 because they are the only room 
// which have gates through them. So,
// answer is 2.

// Example 2:

// Input:
// N = 2, M = 1
// V = [[1, 2]]
// Output: 1

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function captainAmerica() which takes the integer N, an integer M and 2-d array V as input parameters and returns the Total no of rooms.

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(N+M)

 

// Constraints:
// 1 ≤ n ≤ 30000
// 1 ≤ m ≤ 200000
// 1 ≤ p,q ≤ n

// View Bookmarked Problems
// Topic Tags
// We are replacing the old Disqus forum with the new Discussions section given below.
// Click here to view old Disqus comments.





#define vvi vector<vector<int>>
#define vb vector<bool>

class Solution{

public:
    
    void scc_dfs(vvi&adj,int node,vb&visi,unordered_set<int>&scc){
       visi[node]=true;
       scc.insert(node);
       for(int child : adj[node]){
           if(!visi[child])scc_dfs(adj,child,visi,scc);
       }
       return;
   }


   void topo_dfs(vvi&adj,int node,vb&visited,stack<int>&st){
       
       visited[node]=true;
       // cnt++;
       for(int child : adj[node]){
           if(!visited[child])topo_dfs(adj,child,visited,st);
       }
       
       st.push(node);
       return;
   }
   
   void dfsHelper(vvi&adj,stack<int>&st,int n,vb&visited)
   {
       for(int i=1;i<=n;i++){
           if(!visited[i])topo_dfs(adj,i,visited,st);
       }
       return;
   }
   
   void makeGraph(vvi&adj,vvi&rev_adj,vvi&V){
       for(vector<int> a : V){
           if(a.size()==0)continue;
           adj[a[0]].push_back(a[1]);
           rev_adj[a[1]].push_back(a[0]);
       }
   }

   int getOutDegree(vvi&adj, unordered_set<int>&scc){
       
       int cnt = 0;
       for(auto i : scc){
           for(int child : adj[i]){
               if(scc.find(child)==scc.end())cnt++;
           }
           
       }
       return cnt;
   }

   int captainAmerica(int N, int M, vector<vector<int>> &V){
       // Code Here
       
       vector<vector<int>> adj(N+1), rev_adj(N+1);
       makeGraph(adj,rev_adj,V);
       
       stack<int> st;
       
       vector<bool> visited(N+1,false);
       
       dfsHelper(adj,st,N,visited);
       
       for(int i=1;i<=N;i++)visited[i]=false;
       
       int ans = 0;
       int out_degree_cnt = 0;
       while(!st.empty()){
           
           unordered_set<int>scc;
           int top_node = st.top();
           st.pop();
           
           if(!visited[top_node]){
               
               scc_dfs(rev_adj,top_node,visited,scc);
               
               int od = getOutDegree(adj,scc);
               
               if(od==0){
                   out_degree_cnt++;
                     
               int sz = scc.size();
               
                   ans = max(sz,ans);
               }
             
               
           }
           
       }
       return out_degree_cnt>1 ? 0 : ans;
       
   } 
};























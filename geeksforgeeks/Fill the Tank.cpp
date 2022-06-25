// Fill the Tank 
// Medium Accuracy: 51.71% Submissions: 1063 Points: 4
// In a city water tanks are connected by pipeline(As a tree). Since people working at the city corporation are lazy they usually select one of the tank and pour complete amount of water into it, when the tank is filled, the excess water evenly flows to the connected tanks. The head of city corporation has instructed to pour minimum amount of water into the selected tank so that all other tank is filled. As the labours of the corporation are not intelligent enough to figure out the minimum amount of water required to fill all the tanks they have asked your help. Also Maximum amount of water available with city corporation is 1018

// NOTE: If the tank if full, the water flows to all of its connected tanks except the tank from which the water had come to it. i.e, to all tanks except the source for that particular tank. If it has no option to flow the water is considered to be wasted

// Example 1:

// Input:
// N = 4 and S = 1
// Edges = [[1, 2], [2, 3], [3, 4]]
// Cap = [1, 1, 1, 1]
// Output: 5
// Explanation:
// Initially 5 unit of water is poured into 
// tank 1. 2 unit of it flows to tank 2 and 
// 2 unit of it flows into tank 3. From 2 
// unit of water in tank 2 1 unit flows into 
// tank 4 and 1 unit from tank 3 is wasted.



 

// Example 2:

// Input:
// N = 3 and S = 2
// Edges = [[1, 2], [2, 3]]
// Cap = [1, 1, 1]
// Output: 3

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function minimum_amount() which takes an integer N, an integer S, 2-d array Edges, and an array Cap of length N as input parameters and returns the minimum amount of water required to fill all the tanks. If it is not possible to fill all the tanks print -1.

// Expected Time Complexity: O(N*log(S))
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1 ≤ n ≤ 100000
// 1 ≤ s,u,v ≤ n
// 1 ≤ capacity of each tank ≤ 1000000007

// View Bookmarked Problems
// Topic Tags




class Solution {
long long tmp=1e18;
    bool p=false;
public:

    long long dfs(int
 curr,vector<vector<long long>> &adj , vector<bool> &vis ,int *cap)
    {
       vis[curr]=true;
       long long mx=0;
       int l=0;
        for(auto nab : adj[curr])
       {
           if(!vis[nab])
           {
               l++;
               mx=max(mx,dfs(nab,adj,vis,cap));
               if( l*mx > tmp)
               {
                    p=true;
                    return -1;
               }
            }
       }
       return  (cap[curr-1]+mx*l);
    }
    
    long long minimum_amount(vector<vector<int>> &v, int num, int start, int *cap){
       // Code here
       vector<vector<long long>> adj(num+1);
       vector<bool> vis(num+1,false);
        for(int i=0;i<v.size()-1;++i)
       {
           adj[v[i][0]].push_back(v[i][1]);
           adj[v[i][1]].push_back(v[i][0]);
       }
       long long t= dfs(start,adj,vis,cap);
    
        if(p || t>tmp)
        return -1;
        return t;
    }
};











































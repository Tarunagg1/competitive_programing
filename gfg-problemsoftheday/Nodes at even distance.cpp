// Nodes at even distance 
// Medium Accuracy: 63.12% Submissions: 1110 Points: 4
// Given a connected acyclic graph with n nodes and n-1 edges, count the pair of nodes that are at even distance(number of edges) from each other.


// Example 1:

// Input:
// n = 3
// graph = {{}, {2}, {1, 3}, {2}}
// Output: 1
// Explaination: Here there are three pairs {1,2},{1,3}
// and {2,3} and only {1,3} has even distance between them.
// i.e           1
//              /
//             2
//            /
//           3

// Example 2:

// Input:
// n = 5
// graph = {{}, {2,4}, {1,3}, {2}, {1,5}, {4}}
// Output: 4
// Explaination: There are four pairs {1,3},{1,5},{2,4}
// and {3,5} which has even distance.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countOfNodes() which takes the array graph[] (given as Adjacency list) and its size n as input parameters and returns the count of pair of nodes that are at even distance from each other


// Expected Time Complexity: O(V+E)
// Expected Auxiliary Space: O(V)


// Constraints:
// 1 ≤ n ≤ 104

// View Bookmarked Problems
// Topic Tags
// We are replacing the old Disqus forum with the new Discussions section given below.
// Click here to view old Disqus comments.






class Solution{
    public:
    int countOfNodes(vector<int> graph[], int n)
    {
        // code here
        vector<bool>visited(n+1, 0);
        queue<int>q;
        int red=0,black=0;
        q.push(1);
        visited[1]=true;
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            if(level%2==0)black+=sz;
            else red+=sz;
            while(sz--){
                int node=q.front();
                q.pop();
                for(int i=0; i<graph[node].size(); i++)
                {
                    if(!visited[graph[node][i]])
                    {
                        q.push(graph[node][i]);
                        visited[graph[node][i]]=true;
                    }
                }
            }
            level++;
        }
        return ((red*(red-1))/2)+((black*(black-1))/2);
    }
};






















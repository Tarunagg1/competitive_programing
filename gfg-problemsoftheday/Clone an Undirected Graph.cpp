// Clone an Undirected Graph
// MediumAccuracy: 71.09%Submissions: 9K+Points: 4
// Internship Alert!
// Become an SDE Intern by topping this monthly leaderboard!

// banner
// Given a connected undirected graph with n nodes and m edges, with each node having a distinct label from 0 to n-1, create a clone of the graph. Each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

// Note: If the user returns a correct copy of the given graph, then the system will print 1; in the case when an incorrect copy is generated or when the user returns the original node, the system will print 0.

// For Example :

// class Node {
//     val: integer
//     neighbors: List[Node]
// }
// Example 1:

// Input:
// adjList =
// {
//     {1, 3},
//     {0, 2},
//     {1, 3},
//     {0, 2}
// }
// Output: 1
// Explanation:
// 1 is the output that the driver code will print in case
// you successfully cloned the given graph.
// Example 2:

// Input:
// adjList =
// {
//     {1},
//     {0}
// }
// Output: 1
// Explanation:
// 1 is the output that the driver code will print in case
// you successfully cloned the given graph.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function cloneGraph( ) which takes a node will always be the first node of the graph as input and returns the copy of the given node as a reference to the cloned graph.

// Expected Time Complexity: O(n + m).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= n, m <= 104
// 1 <= Node value <= n

class Solution
{
public:
    unordered_map<int, Node *> m;

    Node *dfs(Node *n)
    {
        m[n->val] = new Node(n->val);

        for (Node *nbr : n->neighbors)
            if (m.find(nbr->val) == m.end())
                m[n->val]->neighbors.push_back(dfs(nbr));
            else
                m[n->val]->neighbors.push_back(m[nbr->val]);

        return m[n->val];
    }

    Node *cloneGraph(Node *n)
    {
        return dfs(n);
    }
};

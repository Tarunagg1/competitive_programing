// Circle of strings
// Difficulty: HardAccuracy: 15.56%Submissions: 62K+Points: 8
// Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
// A string X can be chained together with another string Y if the last character of X is the same as the first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and the second with the last character of the string), it will form a circle.

// For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"

// Examples

// Input: arr[] = ["abc", "bcd", "cdf"]
// Output: 0
// Explaination: These strings can't form a circle because no string has 'd'at the starting index.
// Input: arr[] = ["ab" , "bc", "cd", "da"]
// Output: 1
// Explaination: These strings can form a circle of strings.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ length of strings ≤ 20

// Seen this question in a real interview before ?

class Solution
{
public:
    void DFS(char u, unordered_map<char, vector<char>> &adj, unordered_map<int, bool> &visited)
    {
        visited[u] = true;

        for (auto v : adj[u])
        {
            if (visited[v] == false)
            {
                DFS(v, adj, visited);
            }
        }
    }
    int isCircle(vector<string> &arr)
    {
        unordered_map<char, vector<char>> adj;

        for (int i = 0; i < arr.size(); i++)
        {
            int u = arr[i][0];
            int v = arr[i][arr[i].size() - 1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        unordered_map<int, bool> visited;

        for (int i = 0; i < arr.size(); i++)
        {
            if (visited[arr[i][0]] == false)
            {
                DFS(arr[i][0], adj, visited);
                count++;
            }
        }

        int odd = 0;
        for (auto i : adj)
        {
            if (adj[i.first].size() & 1)
            {
                odd++;
            }
        }

        if (count > 1 || odd != 0)
        {
            return 0;
        }
        return 1;
    }
};

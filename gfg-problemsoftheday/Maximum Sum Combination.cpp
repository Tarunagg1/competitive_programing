// Maximum Sum Combination
// MediumAccuracy: 49.69%Submissions: 15K+Points: 4
// Learn Google Cloud with Curated Lab Assignments. Register, Earn Rewards, Get noticed by experts at Google & Land your Dream Job!
// Given two integer array A and B of size N each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum K valid sum combinations from all the possible sum combinations.

// Note : Output array must be sorted in non-increasing order.

// Example 1:

// Input:
// N = 2
// K = 2
// A [ ] = {3, 2}
// B [ ] = {1, 4}
// Output: {7, 6}
// Explanation:
// 7 -> (A : 3) + (B : 4)
// 6 -> (A : 2) + (B : 4)
// Example 2:

// Input:
// N = 4
// K = 3
// A [ ] = {1, 4, 2, 3}
// B [ ] = {2, 5, 1, 6}
// Output: {10, 9, 9}
// Explanation:
// 10 -> (A : 4) + (B : 6)
// 9 -> (A : 4) + (B : 5)
// 9 -> (A : 3) + (B : 6)
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .

// Expected Time Complexity: O(Nlog(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤  105
// 1 ≤ K ≤  N
// 1 ≤ A [ i ] , B [ i ] ≤ 104

class Solution
{
public:
    vector<int> maxCombinations(int n, int K, vector<int> &A, vector<int> &B)
    {
        // code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<int> res;
        pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
        set<pair<int, int>> s;
        s.insert({n - 1, n - 1});

        while (K > 0)
        {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int sum = p.first;
            int x = p.second.first;
            int y = p.second.second;

            res.push_back(sum);
            if (x > 0 && s.find({x - 1, y}) == s.end())
            {
                pq.push({A[x - 1] + B[y], {x - 1, y}});
                s.insert({x - 1, y});
            }
            if (y > 0 && s.find({x, y - 1}) == s.end())
            {
                pq.push({A[x] + B[y - 1], {x, y - 1}});
                s.insert({x, y - 1});
            }
            K -= 1;
        }
        return res;
    }
};

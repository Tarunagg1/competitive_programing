// Shortest Prime Path
// MediumAccuracy: 70.0%Submissions: 10+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation

// You are given two four digit prime numbers Num1 and Num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only one single digit at a time. Every number obtained after changing a digit should be a four digit prime number with no leading zeros.

// Example 1:

// Input:
// Num1 = 1033
// Num2 = 8179
// Output: 6
// Explanation:
// 1033 -> 1733 -> 3733 -> 3739 -> 3779
//                  -> 8779 -> 8179.
// There are only 6 steps required to reach
// Num2 from Num1, and all the intermediate
// numbers are 4 digit prime numbers.
// Example 2:

// Input:
// Num1 = 1033
// Num2 = 1033
// Output:
// 0

// Your Task:
// You don't need to read input or print anything. Your task is to

// Complete the constructor of the class Solution to precompute a list of prime numbers.
// Complete function shortestPath() which takes two integers Num1 and Num2 as input parameters and returns the distance of the shortest path from Num1 to Num2. If it is unreachable then return -1.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1000 ≤ Num1,Num2 ≤ 9999
// Num1 and Num2 are prime numbers.

// View Bookmarked Problems

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 0 or n == 1)
            return false;

        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }
    int shortestPath(int n1, int n2)
    {
        string s1 = to_string(n1);
        string s2 = to_string(n2);

        queue<pair<string, int>> q;
        q.push({s1, 0});
        vector<int> vis(1e5);

        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            vis[stoi(word)] = 1;

            if (word == s2)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                char ch = word[i];

                for (int j = 0; j < 10; j++)
                {
                    if (i == 0 and j == 0)
                        continue;

                    word[i] = char(j + '0');
                    int val = stoi(word);

                    if (isPrime(val) and !vis[val])
                    {
                        vis[val] = 1;
                        q.push({word, steps + 1});
                    }
                }

                word[i] = ch;
            }
        }

        return -1;
    }
};

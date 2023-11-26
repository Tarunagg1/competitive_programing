// Print Pattern
// EasyAccuracy: 56.39%Submissions: 50K+Points: 2
// Black Friday Sale is Ending in Few Hours!
// Last Chance to Get Flat 30% Off

// banner
// Print a sequence of numbers starting with N, without using loop, where replace N with N - 5, until N > 0. After that replace N with N + 5 until N regains its initial value.

// Example 1:

// Input:
// N = 16
// Output:
// 16 11 6 1 -4 1 6 11 16
// Explaination:
// The value decreases until it is greater than 0. After that it increases and stops when it becomes 16 again.
// Example 2:

// Input:
// N = 10
// Output:
// 10 5 0 5 10
// Explaination: It follows the same logic as per the above example.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function pattern() which takes N as input parameters and returns a list containing the pattern.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// -105 ≤ N ≤ 105

class Solution
{
public:
    void fullrecursion(int number, vector<int> &ans)
    {
        // base condition
        if (number <= 0)
        {
            ans.push_back(number);
            return;
        }

        ans.push_back(number);
        fullrecursion(number - 5, ans);
        ans.push_back(number);
    }
    vector<int> pattern(int N)
    {
        // code here
        vector<int> ans;

        fullrecursion(N, ans);

        return ans;
    }
};

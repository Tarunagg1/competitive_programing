// Print the pattern
// EasyAccuracy: 71.49%Submissions: 158Points: 2
// Write a program that receives a number n as input and prints it in the following format as shown below.
// Like for n = 2 the pattern will be:
// 1*2*5*6
// --3*4

// Example 1:

// Input: n = 3
// Output:
// 1*2*3*10*11*12
// --4*5*8*9
// ----6*7
// Explaination: If the pattern shown in question
// is followed, this will be the output.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function pattern() which takes n as input parameter and returns a list of string where each string denotes a new line of the pattern.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 ≤ n ≤ 70

class Solution
{
public:
    vector<string> pattern(int n)
    {
        // code here

        vector<string> ans;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            string t = "";
            for (int j = 0; j < 2 * i; j++)
                t.push_back('-');
            for (int j = 1; j <= n - i; j++)
                t += to_string(cnt++) + "*";
            ans.push_back(t);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            string t = "";
            for (int j = n - 1; j >= i; j--)
                t += to_string(cnt++) + "*";

            t.pop_back();
            ans[i] += t;
        }
        return ans;
    }
};

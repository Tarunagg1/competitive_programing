// Expression Add Operators
// HardAccuracy: 70.21%Submissions: 2K+Points: 8
// Finding A Job Is Now Easier Than Today's Problem! Explore Job Fair 2023

// Given a string S that contains only digits (0-9) and an integer target, return all possible strings to insert the binary operator ' + ', ' - ', or ' * ' between the digits of S so that the resultant expression evaluates to the target value.

// Note: Operands in the returned expressions should not contain leading zeros. For example, 2 + 03 is not allowed whereas 20 + 3 is fine. It is allowed to not insert any of the operators.

// Example 1:

// Input:
// S = "123"
// target = 6
// Output: { "1*2*3", "1+2+3"}
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

// Example 2:

// Input:
// S = "3456237490"
// target = 9191
// Output: { }
// Explanation: There are no expressions that can be created from "3456237490"  to evaluate to 9191.

// Example 3:

// Input:
// S = "12"
// target = 12
// Output: { "12"}
// Explanation: S itself matches the target. No other strings are possible.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function addOperators() which takes string S and integer target as parameters and returns a list of strings that contains all valid possibilities.

// Expected Time Complexity: O(|S|*4|S|)
// Expected Auxiliary Space: O(|s|*3|S|)

// Constraints:
// 1 ≤ |S| ≤ 10
// S consists of only digits.
// -231 ≤ target ≤ 231-1

// View Bookmarked Problems

void f(int ind, string s, int target, vector<string> &ans, string tmp, long long prev, long long res)
{
    if (ind == s.size())
    {
        if (res == target)
            ans.push_back(tmp);

        return;
    }
    string st = "";
    long long curr = 0;
    for (int i = ind; i < s.size(); i++)
    {
        if (i > ind && s[ind] == '0')
            break;
        st += s[i];
        curr = curr * 10 + s[i] - '0';
        if (ind == 0)
            f(i + 1, s, target, ans, tmp + st, curr, curr);
        else
        {
            f(i + 1, s, target, ans, tmp + "+" + st, curr, res + curr);
            f(i + 1, s, target, ans, tmp + "-" + st, -curr, res - curr);
            f(i + 1, s, target, ans, tmp + "*" + st, prev * curr, res - prev + prev * curr);
        }
    }
    return;
}
vector<string> addOperators(string s, int target)
{
    vector<string> ans;
    string tmp = "";
    long long prev = 0;
    f(0, s, target, ans, tmp, prev, 0);
    return ans;
}

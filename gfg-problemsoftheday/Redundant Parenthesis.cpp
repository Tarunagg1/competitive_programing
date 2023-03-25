// Redundant Parenthesis
// HardAccuracy: 86.21%Submissions: 2K+Points: 8
// Win Prize worth ₹6000 with Ease. Register for the Easiest Coding Challenge!

// Given a valid expression containing only binary operators '+', '-', '*', '/' and operands, remove all the redundant parenthesis.

// A set of parenthesis is said to be redundant if, removing them, does not change the value of the expression.

// Note: The operators '+' and '-' have the same priority. '*' and '/' also have the same priority. '*' and '/' have more priority than '+' and '-'.

// Example 1:

// Input:
// Exp = (A*(B+C))
// Output: A*(B+C)
// Explanation: The outermost parenthesis
// are redundant.
// Example 2:

// Input:
// Exp = A+(B+(C))
// Output: A+B+C
// Explanation: All the parenthesis
// are redundant.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function removeBrackets() which takes the string Exp as input parameters and returns the updated expression.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 < Length of Exp < 105
// Exp contains uppercase english letters, '(' , ')', '+', '-', '*' and '/'.

// View Bookmarked Problems

class Solution
{
public:
    string removeBrackets(string Exp)
    {
        char s[Exp.length() + 1];
        strcpy(s, Exp.c_str());
        int n = Exp.length();

        int ans[n + 1];
        memset(ans, 1, sizeof(ans));
        int lasta[n + 1];
        int nxta[n + 1];

        int l = -1;
        for (int i = 0; i < n; i++)
        {
            lasta[i] = l;
            if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/')
                l = s[i];
        }
        l = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            nxta[i] = l;
            if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/')
                l = s[i];
        }

        stack<int> st;
        int sign[256];
        int mp[256];
        memset(sign, -1, sizeof(sign));
        char operand[] = {'*', '+', '-', '/'};

        for (int p = 0; p < n; p++)
        {
            for (char x : operand)
            {
                mp[x] = 0;
                if (x == s[p])
                    sign[x] = p;
            }
            if (s[p] == '(')
                st.push(p);

            else if (s[p] == ')')
            {
                int i = st.top();
                st.pop();
                int j = p;

                int nxt = nxta[j];
                int last = lasta[i];

                for (char x : operand)
                {
                    if (sign[x] >= i)
                    {
                        mp[x] = 1;
                    }
                }
                int ok = 0;

                if (i > 0 && j + 1 < n && s[i - 1] == '(' && s[j + 1] == ')')
                    ok = 1;
                if (mp['+'] == 0 && mp['*'] == 0 && mp['-'] == 0 && mp['/'] == 0)
                    ok = 1;

                if (last == -1 && nxt == -1)
                    ok = 1;
                if (last == '/')
                {
                }
                else if (last == '-' && (mp['+'] == 1 || mp['-'] == 1))
                {
                }
                else if (mp['-'] == 0 && mp['+'] == 0)
                {
                    ok = 1;
                }
                else
                {
                    if ((last == -1 || last == '+' || last == '-') && (nxt == -1 || nxt == '+' || nxt == '-'))
                        ok = 1;
                }
                if (ok == 1)
                {
                    ans[i] = 0;
                    ans[j] = 0;
                }
            }
        }
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (ans[i] > 0)
            {
                res += s[i];
            }
        }
        return res;
    }
};

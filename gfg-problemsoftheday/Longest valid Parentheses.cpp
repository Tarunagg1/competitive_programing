// Longest valid Parentheses
// Difficulty: HardAccuracy: 26.13%Submissions: 104K+Points: 8
// Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

// A parenthesis string is valid if:

// For every opening parenthesis, there is a closing parenthesis.
// Opening parenthesis must be closed in the correct order.
// Examples :

// Input: str = ((()
// Output: 2
// Explaination: The longest valid parenthesis substring is "()".
// Input: str = )()())
// Output: 4
// Explaination: The longest valid parenthesis substring is "()()".
// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)

// Constraints:
// 1 ≤ |str| ≤ 105

class Solution
{
public:
    int maxLength(string &str)
    {
        // code here
        stack<pair<char, int>> st;
        stack<pair<int, int>> range;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                st.push(make_pair(str[i], i));
            }
            else
            {
                if (st.empty() || st.top().first == ')')
                {
                    st.push(make_pair(str[i], i));
                }
                else
                {
                    int l = st.top().second;
                    int r = i;
                    st.pop();
                    while (!range.empty() && range.top().first > l && range.top().second < r)
                    {
                        range.pop();
                    }
                    if (!range.empty() && range.top().second + 1 == l)
                    {
                        l = range.top().first;
                        range.pop();
                    }
                    range.push(make_pair(l, r));
                }
            }
        }
        int ans = 0;
        while (!range.empty())
        {
            int r = range.top().second - range.top().first + 1;
            ans = max(ans, r);
            range.pop();
        }
        return ans;
    }
};

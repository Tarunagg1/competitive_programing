// Geek and Number String
// MediumAccuracy: 34.43%Submissions: 3580Points: 4
// Geek has a string Sof size Nconsisting of characters from '0'to '9'. He wants to minimise the length of the string. In each minimising operation, geek can remove any two consecutive characters if they are of the form {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"}.
// Find the minimum possible length of the string after applying minimising operations.

// Example 1:

// Input:
// N = 5
// S = "12213"
// Output: 1
// Explanation: Geek can get the string of
// length 1 in two minimising operation,
// In 1st operation Geek will remove "12"
// from "12213" then Geek left with "213"
// In 2nd operation Geek will remove "21"
// from "213" then Geek left with "3"

// Example 2:

// Input:
// N = 4
// S = "1350"
// Output: 4
// Explanation: Can't remove any character.

// Your Task:
// You don't need to read input or print anything. Complete the functionminLength() which takes N and S as input parameters and returns the the minimum possible length of the string.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space:O(N)

// Constraints:
// 1 ≤ N ≤ 105


class Solution
{
public:
    int minLength(string s, int n)
    {
        // code here
        stack<char> st;

        for (int i = 0; i < n; i++)

        {

            string str = "";

            if (st.empty())

            {

                st.push(s[i]);
            }

            else
            {

                str += st.top();

                str += s[i];

                if (str == "12" || str == "21" || str == "34" || str == "43" || str == "56" || str == "65" || str == "78" || str == "87" || str == "09" || str == "90")

                {

                    st.pop();
                }

                else
                {

                    st.push(s[i]);
                }
            }
        }

        return st.size();
    }
};

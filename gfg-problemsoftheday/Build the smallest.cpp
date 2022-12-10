// Build the smallest
// MediumAccuracy: 36.78%Submissions: 2K+Points: 4
// Given a number k and string num of digits (0 to 9) denoting a positive integer. Find a string denoting the lowest integer number possible by removing k digits from num, without changing their order.
// Note: num will not contain any leading zero.

// Example 1:

// Input:
// k = 2
// num = "143729"
// Output: "1329"
// Explanation: 1329 is the minimum number
// possible after removing '4' and '7'.

// Example 2:

// Input:
// k = 3
// num = "10056"
// Output: "0"
// Explanation: 0 is the minimum number
// possible after removing '1' , '5' and '6'.

// Your Task:
// You dont need to read input or print anything. Complete the function buildLowestNumber() which accepts string num and integer k as input parameters and returns a string denoting the smallest integer possible after removing k digits from num without changing the order.

// Expected Time Complexity: O(Length of num)
// Expected Auxiliary Space: O(Length of num)

// Constraints:
// 1 <= Length of num <= 105
// 0 <= k < Length of num

// View Bookmarked Problems

string buildLowestNumber(string s, int k)
{
    string ans;
    vector<int> d(s.size());
    stack<int> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        while (st.size() and s[st.top()] >= s[i])
            st.pop();
        if (st.size())
            d[i] = st.top();
        else
            d[i] = -1;
        st.push(i);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (d[i] - i > k or d[i] == -1)
            ans += s[i];
        else
            k--;
    }
    while (ans.size() and k--)
        ans.pop_back();
    int i = 0;
    while (i < ans.size() and ans[i] == '0')
        i++;
    if (i == ans.size())
        return "0";
    return ans.substr(i);
}

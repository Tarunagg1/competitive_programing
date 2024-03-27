// Additive sequence
// MediumAccuracy: 61.34%Submissions: 8K+Points: 4
// Given a string n, your task is to find whether it contains an additive sequence or not. A string n contains an additive sequence if its digits can make a sequence of numbers in which every number is addition of previous two numbers. You are required to complete the function which returns true if the string is a valid sequence else returns false. For better understanding check the examples.

// Note: A valid string should contain at least three digit to make one additive sequence.

// Example 1:

// Input:
// n = "1235813"
// Output:
// 1
// Explanation:
// The given string can be splited into a series of numbers
// where each number is the sum of the previous two numbers:
// 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8, and 5 + 8 = 13. Hence, the output would be 1 (true).
// Example 2:

// Input:
// n = "11235815"
// Output:
// 0
// Explanation:
// We can start with the first two digits: "11".
// First number: 1, Second number: 1, Sum: 1 + 1 = 2
// Now, we have "2" as the next number.
// First number: 1, Second number: 2, Sum: 1 + 2 = 3
// Now, we have "3" as the next number.
// First number: 2, Second number: 3, Sum: 2 + 3 = 5
// Now, we have "5" as the next number.
// First number: 3, Second number: 5, Sum: 3 + 5 = 8
// Now, we have "8" as the next number.
// First number: 5, Second number: 8, Sum: 5 + 8 = 13
// At this point, there is no "13" present in the remaining digits "815". Hence, the output would be 0 (or false).
// User Task:
// Your task is to complete the function isAdditiveSequence() which takes a single string as input n and returns a boolean value indicating whether the given string contains an additive sequence or not. You need not take any input or print anything.

// Expected Time Complexity: O(n3).
// Expected Auxiliary Space: O(1).

// Constraints:
// 3 <= lenght( n ) <= 200
// 1 <= digits of string <= 9

// Topic Tags

string addS(string &s1, string &s2)
{
    string ans = "";
    int n = s1.size();
    int m = s2.length();
    int i = n - 1, j = m - 1;
    int c = 0;
    while (i >= 0 and j >= 0)
    {
        int val = s1[i] - '0' + s2[j] - '0' + c;
        ans.push_back(val % 10 + '0');
        c = val / 10;
        i--, j--;
    }
    while (i >= 0)
    {
        int val = s1[i] - '0' + c;
        ans.push_back(val % 10 + '0');
        c = val / 10;
        i--;
    }
    while (j >= 0)
    {
        int val = s2[j] - '0' + c;
        ans.push_back(val % 10 + '0');
        c = val / 10;
        j--;
    }
    if (c)
        ans.push_back(c + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

public:
bool isAdditiveSequence(string s)
{
    int n = s.length();
    string pre1 = "", pre2 = "";
    int indi = 2;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            pre1 = s.substr(0, i + 1);
            pre2 = s.substr(i + 1, j - (i + 1) + 1);
            string req = addS(pre1, pre2);
            string kk = s.substr(j + 1, req.length());
            if (req == kk)
            {
                indi = j + 1, flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    if (!flag)
        return false;
    while (indi < n)
    {
        string req = addS(pre1, pre2);
        string kk = s.substr(indi, req.length());
        if (req != kk)
            return false;
        indi += req.length();
        pre1 = pre2;
        pre2 = req;
    }
    return true;
}

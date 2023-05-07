// String Mirror
// EasyAccuracy: 56.34%Submissions: 5K+Points: 2
// Finding A Job Is Now Easier Than Today's Problem! Explore Job Fair 2023

// You are given a string str of length n. You want to choose a non-zero integer k (k<=n), such that you can perform the following operation:
// Take the prefix of the string of length k and append the reverse of it to itself.
// Your task is to find the lexicographically smallest string you can get.

// Example 1:

// Input:
// str = "bvdfndkn"
// Output:
// bb
// Explanation:
// "bb" is the lexicographically smallest string you can get. If you choose k>1 the order of the resulting string will increase.

// Example 2:

// Input:
// str = "casd"
// Output:
// caac
// Explanation:
// "caac" is the lexicographically smallest string you can get.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function stringMirror() which takes a String str as input, and returns the lexicographically smallest string.

// Expected Time Complexity: O(|str|)
// Expected Space Complexity: O(|str|)

// Constraints:
// 1 <= |str| <= 105

// View Bookmarked Problems
// Topic Tags

class Solution
{
public:
    string stringMirror(string str)
    {
        // Code here
        int n = str.size();

        string temp;
        temp += str[0];

        for (int i = 1; i < n; i++)
        {
            if (str[i] < str[i - 1])
                temp += str[i];
            else if (str[i] > str[i - 1])
                break;
            else
            { // str[i] == str[i - 1];
                if (str[i] == temp[0])
                    break;
                else
                    temp += str[i];
            }
        }

        string rev = temp;
        reverse(rev.begin(), rev.end());

        return temp + rev;
    }
};

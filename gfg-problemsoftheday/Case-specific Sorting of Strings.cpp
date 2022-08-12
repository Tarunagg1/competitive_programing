// Case-specific Sorting of Strings
// MediumAccuracy: 57.47%Submissions: 19979Points: 4
// Given a string S consisting of uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

// Example 1:

// Input:
// N = 12
// S = defRTSersUXI
// Output: deeIRSfrsTUX
// Explanation: Sorted form of given string
// with the same case of character as that
// in original string is deeIRSfrsTUX
// Example 2:

// Input:
// N = 6
// S = srbDKi
// Output: birDKs
// Explanation: Sorted form of given string
// with the same case of character will
// result in output as birDKs.
// Your Task:
// You only need to complete the function caseSort that takes a string str and length of the string n and returns sorted string.

// Expected Time Complexity: O(Nlog(N)).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 105Case-specific Sorting of Strings
// MediumAccuracy: 57.47%Submissions: 19979Points: 4
// Given a string S consisting of uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

// Example 1:

// Input:
// N = 12
// S = defRTSersUXI
// Output: deeIRSfrsTUX
// Explanation: Sorted form of given string
// with the same case of character as that
// in original string is deeIRSfrsTUX
// Example 2:

// Input:
// N = 6
// S = srbDKi
// Output: birDKs
// Explanation: Sorted form of given string
// with the same case of character will
// result in output as birDKs.
// Your Task:
// You only need to complete the function caseSort that takes a string str and length of the string n and returns sorted string.

// Expected Time Complexity: O(Nlog(N)).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 105

class Solution
{
public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string up = "";
        string lo = "";
        string ans = "";
        for (char i : str)
        {
            if (i >= 'A' and i <= 'Z')
                up.push_back(i);
            if (i >= 'a' and i <= 'z')
                lo.push_back(i);
        }
        sort(up.begin(), up.end());
        sort(lo.begin(), lo.end());
        int k = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] >= 'A' and str[i] <= 'Z')
                ans.push_back(up[k++]);
            if (str[i] >= 'a' and str[i] <= 'z')
                ans.push_back(lo[j++]);
        }
        return ans;
    }
};

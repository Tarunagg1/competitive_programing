// Recursively remove all adjacent duplicates 
// Medium Accuracy: 46.71% Submissions: 25154 Points: 4
// Given a string s, remove all its adjacent duplicate characters recursively. 

// Example 1:

// Input:
// S = "geeksforgeek"
// Output: "gksforgk"
// Explanation: 
// g(ee)ksforg(ee)k -> gksforgk

// Example 2:

// Input: 
// S = "abccbccba"
// Output: ""
// Explanation: 
// ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function remove() which takes the string S as input parameter and returns the resultant string.
// Note: For some test cases, the resultant string would be an empty string. For that case, the function should return the empty string only.


// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(|S|)


// Constraints:
// 1<=|S|<=105

// View Bookmarked Problems


class Solution{
public:
    string remove(string s){
        // code here
        
        while (1)   {
        int n = s.size(), i = 0;
        string tmp;
        while (i < n)   {
            int j = i;
            while (++j < n && s[i] == s[j]);
            if (j == i+1) tmp += s[i];
            i = j;
        }
        if (s.size() == tmp.size()) break;
            s = tmp;
        }
        return s;
    }
};



























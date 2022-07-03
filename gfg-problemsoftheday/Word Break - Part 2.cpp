// Word Break - Part 2 
// Hard Accuracy: 61.08% Submissions: 9484 Points: 8
// Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

// Follow examples for better understanding.

// Example 1:

// Input: s = "catsanddog", n = 5 
// dict = {"cats", "cat", "and", "sand", "dog"}
// Output: (cats and dog)(cat sand dog)
// Explanation: All the words in the given 
// sentences are present in the dictionary.
// Example 2:

// Input: s = "catsandog", n = 5
// dict = {"cats", "cat", "and", "sand", "dog"}
// Output: Empty
// Explanation: There is no possible breaking 
// of the string s where all the words are present 
// in dict.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function wordBreak() which takes n, dict and s as input parameters and returns a list of possible sentences. If no sentence is possible it returns an empty list.

// Expected Time Complexity: O(N2*n) where N = |s|
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ n ≤ 20
// 1 ≤ dict[i] ≤ 15
// 1 ≤ |s| ≤ 500 

// View Bookmarked Problems
// Company Tags


unordered_map<string,int> m;
    vector<string> ans;
    public:
    void fn(string r,string k)
    {
        string p;
        for(int i=1;i<=r.size();i++)
        {
            p=r.substr(0,i);
            if(m[p] && i==r.size())
                ans.push_back(k+p);
            else if(m[p]==1)
                fn(r.substr(i),k+p+" ");
        }

    }
    vector<string> wordBreak(int n, vector<string>& d, string s)
    {
        for(int i=0;i<n;i++)
            m[d[i]]=1;
        fn(s,"");
        return ans;
    }































// Smallest distinct window 
// Medium Accuracy: 50.29% Submissions: 24207 Points: 4
// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

// Example 1:

// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"
// Example 2:
// Input : "aaab"
// Output : 2
// Explanation : Sub-string -> "ab"
 
// Example 3:
// Input : "GEEKSGEEKSFOR"
// Output : 8
// Explanation : Sub-string -> "GEEKSFOR"
 


// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function findSubString() which takes the string  S as input and returns the length of the smallest such window of the string.


// Expected Time Complexity: O(256.N)
// Expected Auxiliary Space: O(256)

 

// Constraints:
// 1 ≤ |S| ≤ 105



class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int n=str.size();
        for(int i=0;i<n;i++)
        mp1[str[i]]++;
        int i=0,j=0,ans=INT_MAX;
        while(j<n)
        {
            mp2[str[j]]++;
            if(mp1.size()==mp2.size())
            {
                while(mp1.size()==mp2.size())
                {
                    mp2[str[i]]--;
                    if(mp2[str[i]]==0)
                    mp2.erase(str[i]);
                    i++;
                }
                ans=min(ans,1+j-i+1);
            }
            j++;
        }
        return ans;
    }
};





























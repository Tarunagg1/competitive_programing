// String formation from substring 
// Medium Accuracy: 44.54% Submissions: 4423 Points: 4
// Given a string s, the task is to check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 

// Example 1:

// Input: s = "ababab"
// Output: 1
// Explanation: It is contructed by 
// appending "ab" 3 times
// Example 2:

// Input: s = "ababac"
// Output: 0
// Explanation: Not possible to construct
// User Task:
// Your task is to complete the function isRepeat() which takes a single string as input and returns 1 if possible to construct, otherwise 0. You do not need to take any input or print anything.

// Expected Time Complexity: O(|s|)
// Expected Auxiliary Space: O(|s|)

// Constraints:
// 1 <= |s| <= 105

// View Bookmarked Problems
// Company Tags



class Solution{
public:	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	      int i, n=s.size(), val;
    string str="", res;
    for(i=0;i<(n/2);i++) {
        str += s[i];
        val=(n/str.size());
        res="";
        while(val--) 
            res+=str;
        if(res==s) return 1;
    }
    return 0;
	}
};
















































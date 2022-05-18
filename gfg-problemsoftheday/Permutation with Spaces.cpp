// Permutation with Spaces 
// Easy Accuracy: 65.33% Submissions: 8325 Points: 2
// Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

// Example 1:

// Input:
// S = "ABC"
// Output: (A B C)(A BC)(AB C)(ABC)
// Explanation:
// ABC
// AB C
// A BC
// A B C
// These are the possible combination of "ABC".
 

// Example 2:

// Input:
// S = "AB"
// Output: (A B)(AB)

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function permutation() which takes the string S as input parameters and returns the sorted array of the string denoting the different permutation (DON'T ADD '(' and ')' it will be handled by the driver code only).

// Expected Time Complexity: O(2^n)
// Expected Auxiliary Space: O(1)

 

// CONSTRAINTS:
// 1 < |S| < 10
// S only contains lowercase and Uppercase English letters.

// View Bookmarked Problems
// Company Tags






class Solution{
public:

    
void helper(string str,int ind,string output,set<string> &s){
       if(ind == str.length()){
           s.insert(output);
           return;
       }
       
       char ch = str[ind];
       output += ch;
       helper(str,ind+1,output,s);
       if(ind < str.length()-1){
           output += ' ';
           helper(str,ind+1,output,s);
       }
   }
   
   vector<string> permutation(string S){
       set<string> s;
       string output;
       helper(S,0,output,s);
       
       vector<string> ans;
       for(auto x: s) ans.push_back(x);
       
       return (ans);
   }
};

























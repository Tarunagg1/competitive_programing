// Transform String 
// Medium Accuracy: 47.31% Submissions: 6168 Points: 4
// Given two strings A and B. Find the minimum number of steps required to transform string A into string B. The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A.

// Example 1:

// Input:
// A = "abd"
// B = "bad"
// Output: 1
// Explanation: The conversion can take place in
// 1 operation: Pick 'b' and place it at the front.
// Example 2:

// Input:
// A = "GeeksForGeeks"
// B = "ForGeeksGeeks"
// Output: 3
// Explanation: The conversion can take
// place in 3 operations:
// Pick 'r' and place it at the front.
// A = "rGeeksFoGeeks"
// Pick 'o' and place it at the front.
// A = "orGeeksFGeeks"
// Pick 'F' and place it at the front.
// A = "ForGeeksGeeks"
// Your Task: 
// You dont need to read input or print anything. Complete the function transform() which takes two strings A and B as input parameters and returns the minimum number of steps required to transform A into B. If transformation is not possible return -1.


// Expected Time Complexity: O(N) where N is max(length of A, length of B) 
// Expected Auxiliary Space: O(1)  


// Constraints:
// 1<= A.length(), B.length() <= 104

 

// View Bookmarked Problems
// Company Tags



class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        string a=A,b=B;
       sort(a.begin(),a.end());
       sort(b.begin(),b.end());
       if(a.length()!=B.length()) return -1;
      for(int i=0;i<a.length();i++) if(a[i]!=b[i]) return -1;
       int i=A.length()-1,j=0,k=B.length()-1;
        while(i>=0&&k>=0){
           
            if(A[i]!=B[k]){
                i--; j++;
            }
            else {
                i--;k--;
            }
            
        }
        
        return j;
    }
};























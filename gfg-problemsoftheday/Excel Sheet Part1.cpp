// Excel Sheet | Part - 1 
// Medium Accuracy: 47.89% Submissions: 16250 Points: 4
// Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
// For N =1 we have column A, for 27 we have AA and so on.

// Note: The alphabets are all in uppercase.

// Example 1:

// Input:
// N = 51
// Output: AY
// Your Task:
// Complete the function ExcelColumn() which takes N as input and returns output string.

// Expected Time Complexity: O(Log(N))
// Expected Auxiliary Space: O(Log(N))

// Constraints:
// 1 ≤ N ≤ 107

// View Bookmarked Problems



class Solution{
    public:
    string ExcelColumn(int N)
    {
        // Your code goes here
        string s="";
        int i=0;
        int rem=0;
        while(N){
            rem=N%26;
            if(rem==0){
                s='Z'+s;
                N=N/26-1;
            }
            else {
                char a= ('A'+rem-1);
                s=a+s;
                N/=26;
            }
        }
        return s;
    }
};













































// Previous number in one swap 
// Medium Accuracy: 32.21% Submissions: 3011 Points: 4
// Given a non-negative number N in the form of string. The task is to apply at most one swap operation on the number N so that the result is just a previous possible number.

// Note:  Leading zeros are not allowed.

 

// Example 1:

// Input :
// S = "12435"
// Output: 
// 12345
// Explanation:
// Although the number 12354 
// will be the largest smaller 
// number from 12435. But it is 
// not possible to make it using 
// only one swap. So swap 
// 4 and 3 and get 12345.
 

// Example 2:

// Input: 
// S = " 12345"
// Output: 
// -1
// Explanation:
// Digits are in increasing order. 
// So it is not possible to 
// make a smaller number from it.
 

// Your Task:

// You don't need to read input or print anything. Your task is to complete the function previousNumber() which takes the string S and returns the previous number of S. If no such number exists return -1;

 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 2<=|Number length |<=105

 

// View Bookmarked Problems

class solution{
    
public:
    string previousNumber(string S){
        // code here 
        int n = S.length();
       int ind = n-1;
       while(ind > 0){
           if(S[ind-1] > S[ind]) break;
           ind--;
       }
       
       if(ind == 0){
           return "-1";
       }
       
       int i = n-1, p = ind;
       char curr = (char)47;
       while(i >= ind){
           if(S[i] < S[ind-1] && S[i] >= curr) p = i, curr = S[i];
           i--;
       }
       
       swap(S[ind-1],S[p]);
       if(S[0] == '0') return ("-1");
       
       return (S);
    }
};





















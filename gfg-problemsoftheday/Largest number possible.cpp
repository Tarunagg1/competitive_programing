// Largest number possible
// EasyAccuracy: 20.26%Submissions: 78K+Points: 2
// 100+ Candidates recieved offers in the last 3 months through Job-A-Thon. Your call is just a click away

// Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'. Return -1 if it is not possible.

// Example 1:

// Input: N = 2, S = 9
// Output: 90
// Explaination: It is the biggest number 
// with sum of digits equals to 9.
// Example 2:

// Input: N = 3, S = 20
// Output: 992
// Explaination: It is the biggest number 
// with sum of digits equals to 20.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function findLargest() which takes N and S as input parameters and returns the largest possible number. Return -1 if no such number is possible.

// Expected Time Complexity: O(N)
// Exepcted Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 104
// 0 ≤ S ≤ 105




class Solution{
public:
string findLargest(int no, int s){
        // code here
          if (s == 0 && no > 1) return "-1";
        string ans =  "";
        int n = 9;
        while (ans.size() < no){
                
                if (s > 9){
                   ans.push_back('9');
                    s = s - 9;
                }
                else {
                    if (s > 0) {
                        ans.push_back(48+s);
                        s-=s;
                    }
                    else ans.push_back('0');
                }
        }
        if (s == 0)
            return ans;
        else if (s!=0) return "-1";
    }
};






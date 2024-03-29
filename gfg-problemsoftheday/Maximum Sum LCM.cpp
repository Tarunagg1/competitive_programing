// Maximum Sum LCM
// EasyAccuracy: 55.64%Submissions: 471Points: 2
// Given a positive number n. You need to write a program to find the maximum sum of distinct numbers such that the LCM of all these numbers is equal to n.

// Example 1:

// Input: n = 2
// Output: 3
// Explanation: The distinct numbers you can have are
// just 1 and 2 and their sum is equal to 3.
// Example 2:

// Input: n = 5
// Output: 6
// Explanation: The distinct numbers you can have
// are just 1 and 5 and their sum is equal to 6.

// Your Task:
// You dont need to read input or print anything. Complete the function maxSumLCM() which takes n as input parameter and returns the maximum sum of distinct numbers such that the LCM of all these numbers is equal to n.

// Expected Time Complexity: O(sqrt(n))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<= N <=1000000000

// View Bookmarked Problems
// Topic Tags

class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        // code here
        long long int ans = 0;
        
        for(int i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                ans+=i;
                long long int m = n/i;
                if(m!=i)
                    ans+=m;
            }
        }
                
        return ans;
    }
};
// Fraction Trouble 
// Easy Accuracy: 66.11% Submissions: 384 Points: 2
// Consider the set of irreducible fractions A = {n/d | n≤d and d ≤ 10000 and gcd(n,d) = 1}.You are given a member of this set and your task is to find the largest fraction in this set less than the given fraction.
// Note : this is a set and all the members are unique.

// Example 1:

// Input: n = 1, d = 4
// Output: {2499, 9997}  
// Explanation: 2499/9997 is the largest fraction.

// Example 2:

// Input: n = 2, d = 4
// Output: {4999, 9999}
// Explanation: 4999/9999 is the largest fraction. 

// Your Task:  
// You dont need to read input or print anything. Complete the function numAndDen() which takes n and d as input parameter and returns the numerator and the denominator of the required irreducible fraction.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= d <=1000

// View Bookmarked Problems






class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
           long double val=(long double)n/(long double)d;
       
        int num=val*10000;
        int den=10000;
        
        
        long double mx=-1;
        vector<int>ans(2);
        
        long double temp=(long double)num/(long double)den;
        do
        {
            
            if(temp<val)
            {
                if(temp>mx)
                {
                    mx=temp;
                    ans[0]=num;
                    ans[1]=den;
                    
                }
                den--;
                
            }
            else
            {
                
                num--;
                
            }
            temp=(long double)num/(long double)den;
            
        }
        while(temp>=0);
        return ans;
    }
};






























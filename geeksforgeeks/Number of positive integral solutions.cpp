// Number of positive integral solutions 
// Medium Accuracy: 61.66% Submissions: 1095 Points: 4
// You are given an equation of the form x1+x2+...+xN=K. You need to find the total number of positive integral solutions of this equation.
 

// Example 1:

// Input: s = a+b=5
// Output: 4
// Explanation: (4,1) , (1,4) , (2,3) , (3,2)

// Example 2:

// Input: s = a+b=1
// Output: 0
// Explanation: No solution exist.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function posIntSol() which takes a string as input and returns number of solutions.
 

// Expected Time Complexity : O(Length of given string)
// Expected Auxiliary Space : O(1)
 

// Constraints:
// 1 <= K <= 25
// 2 <= N <= 10

 

// View Bookmarked Problems
// Topic Tags


class Solution{
public:
long solve(long x,long k)
    {
        if(x>k) return 0;
        if(x==2) return k-1;
        long cnt=0;
        for(int i=1;i<=(k-x+1);i++)
        {
            cnt+=solve(x-1,k-i);
        }
        return cnt;
    }


    long posIntSol(string s)
    {
         long n=s.size();
        int i=n-1;
        while(s[i]!='=') i--;
        int k=0;
        for(int j=i+1;j<n;j++)
        {
            int a=s[j]-'0';
            k=k*10+a;
        }
        n-=2;
        long x=1+((n-1)/2);
        if(k<x) return 0;
        if(x==k) return 1;
        return solve(x,k);
    }
};







































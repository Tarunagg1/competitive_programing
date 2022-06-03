// Tricky Subset Problem 
// Medium Accuracy: 40.48% Submissions: 1865 Points: 4
// N children are made to stand in a queue. Each of them is given a number A[i]. The teacher writes a number S on a page and passes it to the first child. Each child must add all the numbers they see on the page along with their own number, write the sum on the paper and pass it to the next person. 
// In the end, the teacher must determine if X can be formed by adding some of the numbers from the series of numbers written on the paper.

// Example 1:

// Input: 
// S = 1, N = 4, X = 7
// A = {1, 2, 4, 2}
// Output: yes
// Explaination: The final sequence of 
// numbers on the paper is 1, 2, 5, 12, 22. 
// Using 2 and 5 we can form 7. 

// Example 2:

// Input: 
// S = 100, N = 2, X = 500
// A = {51, 88}
// Output: no
// Explaination: The final sequence of 
// numbers on the paper is 100, 151, 339. 
// Using these numbers we cannot form 500.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function isPossible() which takes S, N, X and array A as input parameters and returns 1 if there is a subset which adds to this sum. Otherwise returns 0.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
 

// Constraints
// 1 ≤ N ≤ 105
// 1 ≤ S, Ai , X ≤ 1018  

// View Bookmarked Problems



class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        // code here
          vector<long long>pre;
        pre.push_back(S);
        long long sum = S;
        for(int i = 1 ; i <= N && sum <= X; i++){
            pre.push_back(sum + A[i - 1]);
            sum += pre[i];
        }
        int len = pre.size();
        for(int i = len - 1 ; i >= 0 ;i--){
            if(pre[i] <= X)
            X -= pre[i];
        }
        return X == 0;
    }
};









































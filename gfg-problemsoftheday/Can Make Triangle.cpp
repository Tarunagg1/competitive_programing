// Can Make Triangle 
// Medium Accuracy: 92.04% Submissions: 1332 Points: 4
// Given an array A[] of N elements, You'd like to know how many triangles can be formed with side lengths equal to adjacent elements from A[].

// Construct an array of integers of length N - 2 where ith element is equal to 1 if it is possible to form a triangle with side lengths A[i], A[i+1], and A[i+2]. otherwise 0.

// Note: A triangle can be formed with side lengths a, b and c if a+b>c and a+c>b and b+c>a.

// Example 1:

// Input:
// N = 4
// A[] = {1, 2, 2, 4}
// Output:
// 1 0
// Explanation:
// output[0] = 1 because we can form a 
// triangle with side lengths 1,2 and 2.
// output[1] = 0 because 2+2<4 so, we cannot 
// form a triangle with side lengths 2,2 and 4.
// Example 2:

// Input: 
// N = 5
// A[] = {2, 10, 2, 10, 2}
// Output:
// 0 1 0
// Explanation:
// output[0] = 0 because 2+2<10 so, we cannot
// form a triangle with side lengths 2, 10 and 2. 
// output[1] = 1 we can form a triangle with 
// side lengths 10,2 and 10. 
// output[1] = 0 because 2+2<10 so, we can
// form a triangle with side lengths 2, 10 and 2. 
// Your Task:
// You dont need to read input or print anything. Your task is to complete the function canMakeTriangle() which takes the array A and the integer N as the input parameters, and returns the array of answers.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 3 ≤ N ≤ 105 
// 1 ≤ arr[i] ≤ 109


class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> A, int N){
        // code here
        vector<int> res;
        
        for(int i=0; i<N-2; i++){
            int cond1 = A[i]+A[i+1] > A[i+2];
            int cond2 = A[i]+A[i+2] > A[i+1];
            int cond3 = A[i+1]+A[i+2] > A[i];
            res.push_back(cond1 && cond2 && cond3);
        }
        return res;
    }
}; 


















// Check Mirror in N-ary tree 
// Medium Accuracy: 56.71% Submissions: 9318 Points: 4
// Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.


// Example 1:

// Input:
// n = 3, e = 2
// A[] = {1, 2, 1, 3}
// B[] = {1, 3, 1, 2}
// Output:
// 1
// Explanation:
//    1          1
//  / \        /  \
// 2   3      3    2 
// As we can clearly see, the second tree
// is mirror image of the first.
// Example 2:

// Input:
// n = 3, e = 2
// A[] = {1, 2, 1, 3}
// B[] = {1, 2, 1, 3}
// Output:
// 0
// Explanation:
//    1          1
//  / \        /  \
// 2   3      2    3 
// As we can clearly see, the second tree
// isn't mirror image of the first.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function checkMirrorTree() which takes 2 Integers n, and e;  and two arrays A[] and B[] of size 2*e as input and returns 1 if the trees are mirror images of each other and 0 if not.


// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)


// Constraints:
// 1 <= n,e <= 105

// View Bookmarked Problems
// Company Tags
// Topic Tags
// Related Interview Experiences


class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here 
        unordered_map<int, stack<int>> st;
        for(int i=0; i<2*e; i+=2){
            st[A[i]].push(A[i+1]);
        }
        for(int i=0; i<2*e; i+=2){
            if(st[B[i]].top()!=B[i+1]){
                return 0;
            }
            st[B[i]].pop();
        }
        return 1;
    }
};
































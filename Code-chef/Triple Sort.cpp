// Triple Sort Problem Code: TRPLSRT
// Add problem to Todo list
// Submit
// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// You are given a permutation p1,p2,…,pN of the integers 1 through N. You may perform up to K operations of the following type:

// Choose three pairwise distinct valid indices i1,i2,i3. Note that these indices do not have to be chosen in increasing order.
// Let's denote the values of pi1, pi2 and pi3 before this operation by v1, v2 and v3 respectively.
// Change pi2 to v1, pi3 to v2 and pi1 to v3. In other words, perform a cyclic right shift on the elements pi1,pi2,pi3 in this order.
// For example, the permutation (1,4,3,2,5) can be changed to the permutation (1,5,3,4,2) in one operation by choosing i1=2, i2=4 and i3=5.

// Your task is to sort the permutation in increasing order. Note that you do not have to minimise the number of performed operations.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains two space-separated integers N and K.
// The second line contains N space-separated integers p1,p2,…,pN.
// Output
// For each test case:

// If it is impossible to sort the given permutation using at most K operations, print a single line containing the integer −1.
// Otherwise, first, print a line containing a single integer M (0≤M≤K) ― the number of operations you want to perform.
// Then, print M lines describing these operations. For each i (1≤i≤M), the i-th of these lines should contain three space-separated integers ai, bi and ci (pairwise distinct; 1≤ai,bi,ci≤N) ― the indices on which the i-th operation is performed.
// Constraints
// 1≤T≤100
// 3≤N≤2⋅105
// 1≤pi≤N for each valid i
// p1,p2,…,pN are pairwise distinct
// the sum of all N over all test cases does not exceed 2⋅105
// Subtasks
// Subtask #1 (5 points):

// pi=N−i+1 for each valid i
// N≤400
// K=N2
// Subtask #2 (45 points): K=⌊2N3⌋
// Subtask #3 (50 points): K=⌊N2⌋
// Sample Input 1 
// 1
// 4 2
// 3 2 4 1
// Sample Output 1 
// 1
// 1 3 4
// Explanation
// Example case 1: We can sort the permutation by performing one cyclic right shift operation on the indices 1, 3 and 4.














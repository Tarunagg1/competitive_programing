// Length of longest palindrome in linked list
// MediumAccuracy: 49.91%Submissions: 10804Points: 4
// Given a linked list, the task is to complete the function maxPalindrome() which returns an integer denoting  the length of the longest palindrome list that exist in the given linked list.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of the linked list . Then in the next line are N space separated values of the given linked list.

// Output:
// For each test case output will be the required max length of the palindrome present in the given linked list.

// User Task:
// The task is to complete the function maxPalindrome() which should count the length of longest palindrome in the given list and return it.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 100

// Example:
// Input:
// 2
// 7
// 2 3 7 3 2 12 24
// 5
// 12 4 4 3 14

// Output:
// 5
// 2

// Explanation:
// Testcase 1: 2 -> 3 -> 7 -> 3 -> 2 is the linked list whose nodes leads to a palindrome as 2 3 7 3 2.
 


int dp[200][200];
int a[200];

int maxPalindrome(Node *head)
{
    Node *curr = head;
    int n = 0;
    while(curr) {
        a[n] = curr->data;
        curr = curr->next;
        n++;
    }
    
    int res = 0;
    for(int k=0; k<n; k++) {
        for(int i=0; i+k<n; i++) {
            dp[i][i+k] = 0;
            if(k == 0) dp[i][i+k] = 1;
            else if(a[i] == a[i+k]) {
                if(k == 1) dp[i][i+k] = 1;
                else dp[i][i+k] = dp[i+1][i+k-1];
            }
            if(dp[i][i+k] == 1) 
                res = max(res, k+1);
        }
    }
    
    return res;
}



























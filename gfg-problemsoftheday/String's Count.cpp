// String's Count
// EasyAccuracy: 53.46%Submissions: 28K+Points: 2
// For the first time ever: GATE 2024 introduces DS & AI in its renowned exam. Take its first ever All India Mock Test

// banner
// Given a length n, count the number of strings of length n that can be made using a, b and c with at-most one b and two c allowed.

// Example 1:

// Input: n = 1
// Output: 3
// Explanation: Possible strings are: "a",
// "b" and "c"
// Example 2:

// Input: n = 3
// Output: 19
// Explanation: Number of strings with 3
// occurrances of a: 1
// 2-a and 1-b: 3
// 2-a and 1-c: 3
// 1-a, 1-b and 1-c: 6
// 1-a and 2-c: 3
// 1-b and 2-c: 3
// So, total number of strings of length 3
// is 1 + 3 + 3 + 6 + 3 + 3 = 19
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countStr() which takes the n as inputs and returns the total number of valid strings.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 105

// Company Tags

#define ll long long

long long int countStr(long long int n)
{
    // complete the function here
    if (n == 1)
        return 3;
    if (n == 2)
        return 8;
    ll all_a = 1;
    ll one_b = n;
    ll one_c = n;
    ll one_b_c = n * 1ll * (n - 1);
    ll one_b_two_c = (n * 1ll * (n - 1) * 1ll * (n - 2)) / 2;
    ll two_c = (n * 1ll * (n - 1)) / 2;
    ll ans = all_a + one_b + one_c + one_b_c + one_b_two_c + two_c;
    return ans;
}

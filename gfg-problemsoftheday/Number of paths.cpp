// Number of paths
// MediumAccuracy: 67.64%Submissions: 64K+Points: 4
// Win 2X Geekbits & Get on top of the leaderboard. Register for Weekly Coding Contest

// banner
// The problem is to count all the possible paths from top left to bottom right of an MxN matrix with the constraints that from each cell you can either move to right or down.

// Return answer modulo 109+7.

// Example 1:

// Input:
// M = 3 and N = 3
// Output: 6
// Explanation:
// Let the given input 3*3 matrix is filled 
// as such:
// A B C
// D E F
// G H I
// The possible paths which exists to reach 
// 'I' from 'A' following above conditions 
// are as follows:ABCFI, ABEHI, ADGHI, ADEFI, 
// ADEHI, ABEFI
// Example 2:

// Input:
// M = 1 and N = 4
// Output: 1
// Explanation:
// There is only one direction to go in,
// and thus, there is only one path possible.
// Your Task
// You don't need to read input or print anything. Your task is to complete the function numberOfPaths() which takes the integer M and integer N as input parameters and returns an integer, the number of paths.

// Expected Time Complexity: O(M)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ N ≤ 108
// 1 ≤ M ≤ 105

// Company Tags



class Solution
{
    public:
   
 long long mod = 1e9 + 7;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long numberOfPaths(long long m, long long n) {
    long long N = m + n - 2;
    long long R = min(m - 1, n - 1);
    
    long long numerator = 1;
    long long denominator = 1;

    for (long long i = 0; i < R; i++) {
        numerator = (numerator * (N - i)) % mod;
        denominator = (denominator * (i + 1)) % mod;
    }
    
    long long inverseDenominator = modPow(denominator, mod - 2, mod);
    
    return (numerator * inverseDenominator) % mod;
}
};




























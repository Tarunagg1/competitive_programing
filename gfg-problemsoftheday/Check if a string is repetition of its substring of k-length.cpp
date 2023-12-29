// Check if a string is repetition of its substring of k-length
// MediumAccuracy: 53.15%Submissions: 12K+Points: 4
// Win from a cash prize pool of INR 15,000
// Check out Hack-For-Health Hackathon Now!

// banner
// Given a string s, check if it is possible to convert it into a string that is the repetition of a substring of length k. To convert, we will select two substrings, of length k starting at index i and j (zero-based indexing) such that i and j are divisible by k, and we will replace one substring with the other.

// Example 1:

// Input:
// N = 4
// K = 2
// S = "bdac"
// Output: 1
// Explanation: We can replace either
// "bd" with "ac" or "ac" with "bd"
// Example 2:

// Input:
// N = 5
// K = 2
// S = "abcde"
// Output: 0
// Explanation: Since n % k != 0, it's not
// possible to convert s into a string which
// is a concatanation of a substring with
// length k.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kSubstrConcat() which takes a string s, its length n and an integer k as inputs and return 1 if convertion of the given string is possible, else 0.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 2 <= k < n <= 105

class Solution
{
public:
    int kSubstrConcat(int n, string s, int k)
    {
        // Your Code Here
        if (n % k != 0)
            return 0;
        int i = 0;
        set<string> v;
        while (i < n)
        {
            string r = s.substr(i, k);
            v.insert(r);
            i += k;
        }
        if (v.size() <= 2)
            return 1;
        else
            return 0;
    }
};

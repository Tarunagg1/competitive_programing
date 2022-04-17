// Closest Palindrome
// Hard Accuracy: 44.22% Submissions: 1804 Points: 8
// Given a number num, our task is to find the closest Palindrome number whose absolute difference with given number is minimum. If 2 Palindome numbers have same absolute difference from the given number, then find the smaller one.

// Example 1:

// Input: num = 9
// Output: 9
// Explanation: 9 itself is a palindrome
// number.
// Example 2:

// Input: num = 489
// Output: 494
// Expnataion: closest palindrome numbers from
// 489 are 484 and 494. Absolute difference between
// 489 and 494 is equal to the absolute difference
// between 484 and 489 but 484 is smaller than 494.

// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function closestPalindrome() which takes num as input parameter and returns the closest palindrome.

// Expected Time Complexity: O(log10num)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= num <= 1014

class Solution
{
public:
    long long int getPalindrome(long long left, bool even)
    {
        long long res = left;
        if (!even)
            left = left / 10;
        while (left > 0)
        {
            res = res * 10 + left % 10;
            left /= 10;
        }
        return res;
    }

    long long int closestPalindrome(long long int num)
    {
        // Code here
        string str = to_string(num);
        int len = str.size();
        int i = (len % 2 == 0) ? len / 2 - 1 : len / 2;
        long long left = stoi(str.substr(0, i + 1));

        // input: n 12345
        vector<long long> candidate;
        candidate.push_back(getPalindrome(left, len % 2 == 0));     // 12321
        candidate.push_back(getPalindrome(left + 1, len % 2 == 0)); // 12421
        candidate.push_back(getPalindrome(left - 1, len % 2 == 0)); // 12221
        candidate.push_back((long long)pow(10, len - 1) - 1);       // 9999
        candidate.push_back((long long)pow(10, len) + 1);           // 100001

        long long diff = INT_MAX, res = 0;
        for (long long cand : candidate)
        {
            if (cand == num)
                return num;
            if (abs(cand - num) < diff)
            {
                diff = abs(cand - num);
                res = cand;
            }
            else if (abs(cand - num) == diff)
            {
                res = min(res, cand);
            }
        }
        return res;
    }
};

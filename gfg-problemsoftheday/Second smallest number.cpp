// Second smallest number
// MediumAccuracy: 65.24%Submissions: 5K+Points: 4
// Participate in Monthly Hiring Challenge conducted by GeeksforGeeks !!

// The task is to find the second smallest number with a given sum of digits as S and the number of digits as D.
// Example 1:

// Input:
// S = 9
// D = 2
// Output:
// 27
// Explanation:
// 18 is the smallest number possible with sum = 9
// and total digits = 2, Whereas the second
// smallest is 27.
// Example 2:

// Input:
// S = 16
// D = 3
// Output:
// 178
// Explanation:
// 169 is the smallest number possible with sum is
// 16 and total digits = 3, Whereas the second
// smallest is 178.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function secondSmallest() which takes the two integers S and D respectively and returns a string which is the second smallest number if possible, else return "-1".

// Expected Time Complexity: O(D)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ S ≤ 105
// 1 ≤ D ≤ 105

// View Bookmarked Problems

class Solution
{
public:
    string secondSmallest(int S, int D)
    {
        // code here
        using ll = int;
        string str = string(D, '0');
        int sum = 0, dig = D;
        ll rem = S;
        int i, j;
        i = D - 1;
        while (rem && i >= 0)
        {
            if (rem > 9)
            {
                rem = rem - 9;
                str[i] = '9';
                i--;
            }
            else
            {
                if (i > 0)
                {
                    rem--;
                    str[0] = '1';
                }
                str[i] = (char)((rem + 48));
                rem = 0;
                i--;
                break;
            }
        }

        if (str[0] == '9')
        {
            return "-1";
        }
        if (rem && i < 0)
        {
            return "-1";
        }
        i = D - 1;
        char ch = str[i];
        while (i >= 0 && str[i] == ch)
        {
            i--;
        }
        str[i] += 1;
        str[i + 1] -= 1;
        return str;
    }
};

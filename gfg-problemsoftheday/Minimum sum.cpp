// Minimum sum
// Difficulty: MediumAccuracy: 17.14%Submissions: 111K+Points: 4
// Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.

// Examples :

// Input: arr[] = [6, 8, 4, 5, 2, 3]
// Output: 604
// Explanation: The minimum sum is formed by numbers 358 and 246.
// Input: arr[] = [5, 3, 0, 7, 4]
// Output: 82
// Explanation: The minimum sum is formed by numbers 35 and 047.
// Input: arr[] = [9, 4]
// Output: 13
// Explanation: The minimum sum is formed by numbers 9 and 4.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 9

class Solution
{
public:
    string toSum(string &s1, string &s2)
    {
        string res = "";
        int carry = 0;
        int n = s1.size(), m = s2.size();
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0)
        {
            int sum = (s1[i] - '0') + (s2[j] - '0') + carry;
            if (sum == 0)
                break;
            carry = sum / 10;
            res += to_string(sum % 10);
            i--;
            j--;
        }
        while (i >= 0)
        {
            int sum = (s1[i] - '0') + carry;
            if (sum == 0)
                break;
            carry = sum / 10;
            res += to_string(sum % 10);
            i--;
        }
        while (j >= 0)
        {
            int sum = (s2[j] - '0') + carry;
            if (sum == 0)
                break;
            carry = sum / 10;
            res += to_string(sum % 10);
            j--;
        }
        if (carry > 0)
            res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
    string minSum(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        string num1 = "", num2 = "";
        for (int i = 0; i < arr.size(); i++)
        {
            if (i % 2 == 0)
                num1 += to_string(arr[i]);
            else
                num2 += to_string(arr[i]);
        }
        return toSum(num1, num2);
    }
};

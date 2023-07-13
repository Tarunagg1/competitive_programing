// Unique Number of Occurrences
// EasyAccuracy: 66.87%Submissions: 8K+Points: 2
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !
// Given an array arr of N integers, the task is to check whether the frequency of the elements in the array is unique or not. Or in other words, there are no two distinct numbers in array with equal frequency. If all the frequency is unique then return true, else return false.

// Example 1:

// Input:
// N = 5
// arr = [1, 1, 2, 5, 5]
// Output:
// false
// Explanation:
// The array contains 2 (1’s), 1 (2’s) and 2 (5’s), since the number of frequency of 1 and 5 are the same i.e. 2 times. Therefore, this array does not satisfy the condition.
// Example 2:

// Input:
// N = 10
// arr = [2, 2, 5, 10, 1, 2, 10, 5, 10, 2]
// Output:
// true
// Explanation:
// Number of 1’s -> 1
// Number of 2’s -> 4
// Number of 5’s -> 2
// Number of 10’s -> 3.
// Since, the number of occurrences of elements present in the array is unique. Therefore, this array satisfy the condition.
// Your task:
// You don't need to read input or print anything. Your task is to complete the function isFrequencyUnique() which take integer N and array arr of size N as arguments, and returns a boolean.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <=105
// -109 <= arr[i] <= 109

class Solution
{
public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int m = mp.size();
        set<int> s;
        for (auto it : mp)
        {
            s.insert(it.second);
        }
        int l = s.size();
        if (m == l)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

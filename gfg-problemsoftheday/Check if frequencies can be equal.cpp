// Check if frequencies can be equal
// MediumAccuracy: 16.67%Submissions: 61K+Points: 4
// Internship Alert!
// New month-> Fresh Chance to top the leaderboard and get SDE Internship!

// banner
// Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

// Note: The driver code print 1 if the value returned is true, otherwise 0.

// Example 1:

// Input:
// s = "xyyz"
// Output:
// 1
// Explanation:
// Removing one 'y' will make frequency of each character to be 1.
// Example 2:

// Input:
// s = "xxxxyyzz"
// Output:
// 0
// Explanation:
// Frequency can not be made same by removing at most one character.
// Your Task:
// You dont need to read input or print anything. Complete the function sameFreq() which takes a string as input parameter and returns a boolean value denoting if same frequency is possible or not.

// Expected Time Complexity: O(|s|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |s| <= 105

// Company Tags

class Solution
{
public:
    bool sameFreq(string s)
    {
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }

        int prev = INT_MAX;

        int l1 = 0;

        for (auto it : m)
        {
            prev = min(prev, it.second);
        }

        int f = 0;
        for (auto it : m)
        {
            if (prev == it.second)
            {
                f++;
            }
        }

        for (auto it : m)
        {
            if (prev != 1 || (prev == 1 && f > 1))
            {
                if (abs(prev - it.second) > 1)
                {
                    return false;
                }
                else if (abs(prev - it.second) == 1)
                {
                    if (l1 == 0)
                    {
                        l1++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else if (prev == 1 && f == 1)
            {
                if (abs(prev - it.second) > 1)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

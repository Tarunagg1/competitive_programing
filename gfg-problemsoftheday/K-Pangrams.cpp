// K-Pangrams
// Difficulty: EasyAccuracy: 20.91%Submissions: 32K+Points: 2
// Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, else return false.

// A single operation consists of swapping an existing alphabetic character with any other alphabetic character.

// Note - A pangram is a sentence containing every letter in the english alphabet.

// Examples :

// Input: str = "the quick brown fox jumps over the lazy dog", k = 0
// Output: true
// Explanation: the sentence contains all 26 characters and is already a pangram.
// Input: str = "aaaaaaaaaaaaaaaaaaaaaaaaaa", k = 25
// Output: true
// Explanation: The word contains 26 instances of 'a'. Since only 25 operations are allowed. We can keep 1 instance and change all others to make str a pangram.
// Input: str = "a b c d e f g h i j k l m", k = 20
// Output: false
// Explaanation: Since there are only 25 charaacters only in this case, so no amount of swapping we can have complete alphabets here.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<= str.size() <= 105
// 0<= k <= 50
// str may contain duplicate characters.
// str contains only lowercase alphabets or spaces.

class Solution
{
public:
    bool kPangram(string str, int k)
    {
        unordered_map<char, int> mpp;
        int n = str.length();
        int check_cnt = 0;

        // Initial Check whether the length of string is less than 26 or not
        for (int i = 0; i < n; i++)
        {
            if (str[i] != ' ')
                check_cnt++;
        }
        if (check_cnt < 26)
            return false;

        // Initialising an unordered map with 26 char as keys and assign values 0
        for (int i = 0; i < 26; i++)
        {
            mpp[i + 97] = 0;
        }

        // Increment the char value by one if it is present in map
        for (int i = 0; i < n; i++)
        {
            if (str[i] != ' ')
                mpp[str[i]]++;
        }

        // Counting the number of missing character in the string
        int cnt = 0;
        for (auto it : mpp)
        {
            if (it.second == 0)
                cnt++;
        }
        return cnt <= k;
    }
};

// Non Repeating Character
// Difficulty: EasyAccuracy: 40.43%Submissions: 238K+Points: 2
// Given a string s consisting of lowercase Latin Letters. Return the first non-repeating character in s. If there is no non-repeating character, return '$'.
// Note: When you return '$' driver code will output -1.

// Examples:

// Input: s = "geeksforgeeks"
// Output: 'f'
// Explanation: In the given string, 'f' is the first character in the string which does not repeat.
// Input: s = "racecar"
// Output: 'e'
// Explanation: In the given string, 'e' is the only character in the string which does not repeat.
// Input: s = "aabbccc"
// Output: -1
// Explanation: All the characters in the given string are repeating.
// Constraints:
// 1 <= s.size() <= 105

// Company

class Solution
{
public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s)
    {
        // Your code here
        // Step 1: Create a frequency array for 26 lowercase letters.
        vector<int> frequency(26, 0); // Initialize all frequencies to 0.

        // Step 2: Traverse the string and count frequencies.
        for (char ch : s)
        {
            frequency[ch - 'a']++; // Increment frequency of the current character.
        }

        // Step 3: Traverse the string again to find the first non-repeating character.
        for (char ch : s)
        {
            if (frequency[ch - 'a'] == 1)
            {
                return ch; // Return the first character with frequency 1.
            }
        }

        // Step 4: If no non-repeating character is found, return '$'.
        return '$';
    }
};

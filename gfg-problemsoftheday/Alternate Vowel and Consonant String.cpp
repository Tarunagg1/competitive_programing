// Alternate Vowel and Consonant String
// MediumAccuracy: 27.78%Submissions: 3471Points: 4
// Given a string S of lowercase english characters. Rearrange characters of the given string such that the vowels and consonants occupy alternate positions and the string so formed should be lexicographically (alphabetically) smallest.
// Note: Vowels are 'a', 'e', 'i', 'o' and 'u'.

// Example 1:

// Input:
// S = "aeroplane"
// Output: alanepero
// Explanation: alanepero
// The vowels and cosonants are arranged
// alternatively with vowels shown in bold.
// Also, there's no lexicographically smaller
// string possible with required conditions.
// Example 2:

// Input:
// S = "mississippi"
// Output: -1
// Explanation: The number of vowels is 4
// whereas the number of consonants is 7.
// Hence, there's no way to arrange the
// vowels and consonants alternatively.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function rearrange() which takes the string S and its size N as inputs and returns the modified string as stated in the description. If such a modification is not possible, return the string "-1".

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(2*26).

// Constraints:
// 1 <= N <= 10^6
// 'a' <= S[ i ] <= 'z'

// View Bookmarked Problems

class Solution
{
public:
    bool isVowel(char ch)
    {

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {

            return true;
        }

        return false;
    }

    char getVowel(int arr[])
    {

        for (int i = 0; i < 26; i++)
        {

            if (isVowel((char)(i + 'a')) && arr[i])
            {

                arr[i]--;

                return (char)(i + 'a');
            }
        }

        return '0';
    }

    char getConsonant(int arr[])
    {

        for (int i = 0; i < 26; i++)
        {

            if (!isVowel((char)(i + 'a')) && arr[i])
            {

                arr[i]--;

                return (char)(i + 'a');
            }
        }

        return '0';
    }

    string rearrange(string S, int N)

    {

        int arr[26] = {0};

        int cntConsonants = 0, cntVowels = 0;

        for (int i = 0; i < N; i++)
        {

            arr[S[i] - 'a']++;

            if (isVowel(S[i]))
                cntVowels++;

            else
                cntConsonants++;
        }

        string ans = "";

        while (ans.size() != N)
        {

            if (ans.size() % 2 == 0)
            {

                if (cntVowels >= cntConsonants)
                {

                    char ch = getVowel(arr);

                    if (ch == '0')
                        return "-1";

                    ans += ch;
                }

                else
                {

                    char ch = getConsonant(arr);

                    if (ch == '0')
                        return "-1";

                    ans += ch;
                }
            }

            else
            {

                if (cntVowels >= cntConsonants)
                {

                    char ch = getConsonant(arr);

                    if (ch == '0')
                        return "-1";

                    ans += ch;
                }

                else
                {

                    char ch = getVowel(arr);

                    if (ch == '0')
                        return "-1";

                    ans += ch;
                }
            }
        }

        return ans;
    }
};

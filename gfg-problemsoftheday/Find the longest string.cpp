// Find the longest string
// MediumAccuracy: 17.65%Submissions: 17+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation

// Given an array of strings arr[]. You have to find the longest string which is lexicographically smallest and also all of its prefix strings are already present in the array.

// Example 1:

// Input: ab a abc abd
// Output: abc
// Explanation: We can see that length of the longest
// string is 3. And there are two string "abc" and "abd"
// of length 3. But for string "abc" , all of its prefix
// "a" "ab" "abc" are present in the array. So the
// output is "abc".
// Example 2:

// Input: ab a aa abd abc abda abdd abde abdab
// Output: abdab
// Explanation: We can see that each string is fulfilling
// the condition. For each string, all of its prefix
// are present in the array.And "abdab" is the longest
// string among them. So the ouput is "abdab".

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestString() which takes the array arr[] as input parameter and returns the longest string which is also lexicographically smallest.And if there is no such string return empty string.

// Expected Time Complexity: O(NlogN)
// Expected Space Complexity: O(N)

// Constraints:
// 1 <= length of arr[] <= 103
// 1 <= arr[i].length <=30

// View Bookmarked Problems
// Company Tags

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        set<string> s;

        string ans;

        for (auto i : words)
            s.insert(i);

        sort(words.begin(), words.end());

        for (auto i : words)
        {

            string str = i, temp;

            bool flag = true;

            for (int j = 0; j < str.size(); j++)
            {

                temp += str[j];

                if (!s.count(temp))
                {

                    flag = false;

                    break;
                }
            }

            if (flag and str.size() > ans.size()) // previously ans stored a and ab so to get new string str.size() shoudl be greater than ans.size()

                ans = str;
        }

        return ans;
    }
};

// Winner of an election
// EasyAccuracy: 53.75%Submissions: 58K+Points: 2
// Win from a cash prize pool of INR 15,000
// Check out Hack-For-Health Hackathon Now!

// banner
// Given an array of n names arr of candidates in an election, where each name is a string of lowercase characters. A candidate name in the array represents a vote casted to the candidate. Print the name of the candidate that received the maximum count of votes. If there is a draw between two candidates, then print lexicographically smaller name.

// Example 1:

// Input:
// n = 13
// arr[] = {john,johnny,jackie,johnny,john
// jackie,jamie,jamie,john,johnny,jamie,
// johnny,john}
// Output: john 4
// Explanation: john has 4 votes casted for
// him, but so does johny. john is
// lexicographically smaller, so we print
// john and the votes he received.
// Example 2:

// Input:
// n = 3
// arr[] = {andy,blake,clark}
// Output: andy 1
// Explanation: All the candidates get 1
// votes each. We print andy as it is
// lexicographically smaller.
// Your Task:
// You only need to complete the function winner() that takes an array of strings arr, and length of arr n as parameters and returns an array of string of length 2. First element of the array should be the name of the candidate and second element should be the number of votes that candidate got in string format.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 105
// 1 <= |arri| <= 105

// Company Tags

class Solution
{
public:
    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        vector<string> ans;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int mx = 0;
        for (auto it : mp)
        {
            mx = max(mx, it.second);
        }
        set<string> st;
        for (auto it : mp)
        {
            if (it.second == mx)
                st.insert(it.first);
        }
        auto it = st.begin();
        ans.push_back(*it);
        ans.push_back(to_string(mx));
        return ans;
    }
};

// Geek and Strings
// MediumAccuracy: 69.85%Submissions: 996Points: 4
// Geek has a list Li containing (not necessarily distinct) N words and Q queries. Each query consists of a string x. For each query, find how many strings in the List Li has the string x as its prefix.

// Example 1:

// Input:
// N = 5, Q = 5
// li[] = {'abracadabra', 'geeksforgeeks',
//       'abracadabra', 'geeks', 'geeksthrill'}
// query[] = {'abr', 'geeks', 'geeksforgeeks',
//          'ge', 'gar'}

// Output: 2 3 1 3 0

// Explaination:
// Query 1: The string 'abr' is prefix of
// two 'abracadabra'.
// Query 2: The string 'geeks' is prefix of three
// strings 'geeksforgeeks', 'geeks' and 'geeksthrill'.
// Query 3: The string 'geeksforgeeks' is prefix
// of itself present in li.
// Query 4: The string 'ge' also is prefix of three
// strings 'geeksforgeeeks', 'geeks', 'geeksthrill'.
// Query 5: The string 'gar' is not a prefix of any
// string in li.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function prefixCount() which takes N, Q, li[] and query[] as input parameters and returns a list containing the count of prefixes for each query.

// Expected Time Complexity: O(Q*x)
// Expected Auxiliary Space: O(N*li [i])

// Constraints:
// 1 ≤ N ≤ 3 x 104
// 1 ≤ Q ≤ 104
// 1 ≤ |li[i]|, |x| ≤ 100

class Solution
{
public:
    vector<int> prefixCount(int n, int Q, string li[], string query[])
    {
        // code here
        unordered_map<string, int> mp;

        for (int i = 0; i < Q; i++)

            mp[query[i]] = 1;

        for (int i = 0; i < n; i++)

        {

            string temp = "", str = li[i];

            for (int j = 0; j < str.size(); j++)

            {

                temp += str[j];

                if (mp[temp])

                    mp[temp]++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < Q; i++)

            ans.push_back(mp[query[i]] - 1);

        return ans;
    }
};

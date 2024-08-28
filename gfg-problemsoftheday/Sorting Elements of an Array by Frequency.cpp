// Sorting Elements of an Array by Frequency
// Difficulty: MediumAccuracy: 44.93%Submissions: 60K+Points: 4
// Given an array of integers arr, sort the array according to the frequency of elements, i.e. elements that have higher frequency comes first. If the frequencies of two elements are the same, then the smaller number comes first.

// Examples :

// Input: arr[] = [5, 5, 4, 6, 4]
// Output: [4, 4, 5, 5, 6]
// Explanation: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are the same the smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6. The output is 4 4 5 5 6.
// Input: arr[] = [9, 9, 9, 2, 5]
// Output: [9, 9, 9, 2, 5]
// Explanation: The highest frequency here is 3. Element 9 has the highest frequency So 9 9 9 comes first. Now both 2 and 5 have the same frequency. So we print smaller elements first. The output is 9 9 9 2 5.
// Expected Time Complexity: O(n*logn)
// Expected Space Complexity: O(n)

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i]≤ 106

// Seen this question in a real interview before ?

bool static cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

class Solution
{
public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int> &arr)
    {
        // Your code here
        map<int, int> mp;
        for (auto &i : arr)
            mp[i]++;

        vector<pair<int, int>> v;
        for (auto &i : mp)
            v.push_back({i.first, i.second});

        sort(v.begin(), v.end(), cmp);

        vector<int> ans;
        for (auto i : v)
        {
            for (int j = 0; j < i.second; j++)
                ans.push_back(i.first);
        }
        return ans;
    }
};

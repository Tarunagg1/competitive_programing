// Kth Smallest
// Difficulty: MediumAccuracy: 35.17%Submissions: 616K+Points: 4
// Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.

// Follow up: Don't solve it using the inbuilt sort function.

// Examples :

// Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
// Output:  7
// Explanation: 3rd smallest element in the given array is 7.
// Input: arr[] = [7, 10, 4, 20, 15], k = 4
// Output:  15
// Explanation: 4th smallest element in the given array is 15.
// Expected Time Complexity: O(n+(max_element) )
// Expected Auxiliary Space: O(max_element)
// Constraints:
// 1 <= arr.size <= 106
// 1<= arr[i] <= 106
// 1 <= k <= n

// Seen this question in a real interview before ?

class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        // code here
        set<int> st(arr.begin(), arr.end());
        auto it = st.begin();
        advance(it, k - 1);
        return *it;
    }
};

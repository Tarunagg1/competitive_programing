// Next Permutation
// Difficulty: MediumAccuracy: 40.66%Submissions: 142K+Points: 4
// Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order).

// Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

// Examples:

// Input: arr = [2, 4, 1, 7, 5, 0]
// Output: [2, 4, 5, 0, 1, 7]
// Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.
// Input: arr = [3, 2, 1]
// Output: [1, 2, 3]
// Explanation: As arr[] is the last permutation, the next permutation is the lowest one.
// Input: arr = [3, 4, 2, 5, 1]
// Output: [3, 4, 5, 1, 2]
// Explanation: The next permutation of the given array is {3, 4, 5, 1, 2}.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105

class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        // code here
        // idx1 - first index from array end downwards
        int idx1 = arr.size() - 1;
        // idx2 - second index for second and third steps
        int idx2 = idx1;
        // num - check for greater number
        int num = arr[idx1];
        // step 1: find the smaller previous element
        while (idx1 > 0 && num <= arr[idx1])
        {
            num = arr[idx1];
            idx1--;
        }
        // exlude the case of highest permutation
        if (num > arr[idx1])
        {
            // step 2: find element after the smallest
            while (idx1 < idx2 & arr[idx1] >= arr[idx2])
            {
                idx2--;
            }
            // swap elements, increase first index and reset second index
            swap(arr[idx1], arr[idx2]);
            idx1++;
            idx2 = arr.size() - 1;
        }
        // step 3: reverse rest of the array
        while (idx1 < idx2)
        {
            swap(arr[idx1], arr[idx2]);
            idx1++;
            idx2--;
        }
    }
};

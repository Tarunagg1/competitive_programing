// Non-Repeating Element
// Easy Accuracy: 56.65% Submissions: 9088 Points: 2
// Find the first non-repeating element in a given array arr of N integers.
// Note: Array consists of only positive and negative integers and not zero.

// Example 1:

// Input : arr[] = {-1, 2, -1, 3, 2}
// Output : 3
// Explanation:
// -1 and 2 are repeating whereas 3 is
// the only number occuring once.
// Hence, the output is 3.

// Example 2:

// Input : arr[] = {1, 1, 1}
// Output : 0

// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function firstNonRepeating() that takes an array (arr), sizeOfArray (n), and returns the first non-repeating element. The driver code takes care of the printing.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 107
// -1016 <= Ai <= 1016
// {Ai !=0 }

class Solution
{
public:
    int firstNonRepeating(int arr[], int n)
    {
        // Complete the function
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
            umap[arr[i]]++;

        for (int i = 0; i < n; i++)
        {
            int key = arr[i];
            auto temp = umap.find(key);
            if (temp->second == 1)
                return key;
        }

        return 0;
    }
};

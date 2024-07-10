// Closest Three Sum
// Difficulty: MediumAccuracy: 17.65%Submissions: 54K+Points: 4
// Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

// Note: If there are multiple solutions, return the maximum one.

// Examples :

// Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
// Output: 2
// Explanation: There is only one triplet present in the array where elements are -7,8,1 whose sum is 2.
// Input: arr[] = [5, 2, 7, 5], target = 13
// Output: 14
// Explanation: There is one triplet with sum 12 and other with sum 14 in the array. Triplet elements are 5, 2, 5 and 2, 7, 5 respectively. Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 3 ≤ arr.size() ≤ 103
// -105 ≤ arr[i] ≤ 105
// 1 ≤ target ≤ 105

class Solution
{
public:
    int threeSumClosest(vector<int> arr, int target)
    {
        // Your code goes here
        sort(arr.begin(), arr.end());

        int prevDiff = INT_MAX;   // Variable to track the minimum difference
        int closestSum = INT_MIN; // Initialize closestSum with the minimum integer value

        // Iterate through each element
        for (int i = 0; i < arr.size() - 2; i++)
        {
            int start = i + 1;        // Initialize start pointer
            int end = arr.size() - 1; // Initialize end pointer

            while (start < end)
            {
                int sum = arr[i] + arr[start] + arr[end]; // Calculate the sum of three numbers

                // If the exact target sum is found
                if (sum == target)
                    return sum;

                int currentDiff = abs(sum - target);

                // Update closestSum if a closer sum is found or if the same difference is found but sum is larger
                if (currentDiff < prevDiff || (currentDiff == prevDiff && sum > closestSum))
                {
                    prevDiff = currentDiff;
                    closestSum = sum;
                }

                // Move pointers based on the sum comparison with the target
                if (sum < target)
                {
                    start++;Largest square formed in a matrix


                }
                else
                {
                    end--;
                }
            }
        }
        return closestSum;
    }
};

// Minimize Max Distance to Gas Station
// HardAccuracy: 38.36%Submissions: 21K+Points: 8
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where n = size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.

// Example 1:

// Input:
// n = 10
// stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// k = 9
// Output: 0.50
// Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
// Example 2:

// Input:
// n = 10
// stations = [3,6,12,19,33,44,67,72,89,95]
// k = 2
// Output: 14.00
// Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer k as inputs and returns the smallest possible value of d. Find the answer exactly to 2 decimal places.

// Expected Time Complexity: O(n*log k)
// Expected Auxiliary Space: O(1)

// Constraint:
// 10 <= n <= 5000
// 0 <= stations[i] <= 109
// 0 <= k <= 105

// stations is sorted in a strictly increasing order.

// Seen this question in a real interview before ?
// 1/4
// Yes
// No

class Solution
{
public:
    bool isValid(double maxDist, vector<int> &positions, int maxNewPoints)
    {
        int n = positions.size();
        int requiredNewPoints = 0;

        for (int i = 1; i < n; i++)
        {
            int distance = positions[i] - positions[i - 1];
            double numNewPoints = (double)distance / maxDist;
            requiredNewPoints += ((int)numNewPoints);
        }

        // Check if the number of required new points is within the allowed limit
        return requiredNewPoints <= maxNewPoints;
    }

    double findSmallestMaxDist(vector<int> &arr, int k)
    {
        int n = arr.size();
        double low = 0;
        double high = arr[n - 1] - arr[0];
        double result = high;

        // Sort the positions to ensure correct distance calculations
        sort(arr.begin(), arr.end());

        // Perform binary search to find the minimum possible maximum distance
        while (high - low > 1e-6)
        {
            double mid = low + (high - low) / 2;

            // Check if it's possible to place points such that the max distance is mid
            if (isValid(mid, arr, k))
            {
                high = mid;
                result = mid;
            }
            else
            {
                low = mid;
            }
        }

        return result;
    }
};

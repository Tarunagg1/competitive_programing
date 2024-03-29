// Maximize the sum of selected numbers from a sorted array to make it empty
// MediumAccuracy: 68.36%Submissions: 6337Points: 4
// Lamp
// Geek Week 2022 is LIVE! Click Here to View All the Exciting Offers!

// Given a array of N numbers, we need to maximize the sum of selected numbers. At each step, you need to select a number Ai, delete one occurrence of Ai-1 (if exists), and Ai each from the array. Repeat these steps until the array gets empty. The problem is to maximize the sum of the selected numbers.

// Note: Numbers need to be selected from maximum to minimum.

// Example 1:

// Input : arr[ ] = {1, 2, 2, 2, 3, 4}
// Output : 10
// Explanation:
// We select 4, so 4 and 3 are deleted leaving us with {1,2,2,2}.
// Then we select 2, so 2 & 1 are deleted. We are left with{2,2}.
// We select 2 in next two steps, thus the sum is 4+2+2+2=10.

// Example 2:

// Input : arr[ ] = {1, 2, 3}
// Output :  4
// Explanation: We select 3, so 3 and 2 are deleted leaving us with {1}. Then we select 1, 0 doesn't exist so we delete 1. thus the sum is 3+1=4.

// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function maximizeSum() that takes an array (arr), sizeOfArray (n), and return the maximum sum of the selected numbers. The driver code takes care of the printing.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ A[i] ≤ 105

// View Bookmarked Problems

class Solution
{
public:
    int maximizeSum(int a[], int n)
    {
        // Complete the function

        int result = 0, i = n - 1;

        int currentmax, currentmaxpos, j;

        while (1)

        {

            if (i < 0)

                return result;

            currentmax = a[i];

            // printf("%d,",currentmax);

            currentmaxpos = i;

            for (j = currentmaxpos - 1; j >= 0; j--)

            {

                if (a[j] == currentmax - 1)

                {

                    a[j] = -1;

                    break;
                }
            }
            result += currentmax;

            i--;
            while (i >= 0 && a[i] == -1)
                i--;
        }
    }
};

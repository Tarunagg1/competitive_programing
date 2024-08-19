// Split an array into two equal Sum subarrays
// Difficulty: EasyAccuracy: 68.8%Submissions: 7K+Points: 2
// Given an array of integers arr, return true if it is possible to split it in two subarrays (without reordering the elements), such that the sum of the two subarrays are equal. If it is not possible then return false.

// Examples:

// Input: arr = [1, 2, 3, 4, 5, 5]
// Output: true
// Explanation: In the above example, we can divide the array into two subarrays with eqaul sum. The two subarrays are: [1, 2, 3, 4] and [5, 5]. The sum of both the subarrays are 10. Hence, the answer is true.
// Input: arr = [4, 3, 2, 1]
// Output: false
// Explanation: In the above example, we cannot divide the array into two subarrays with eqaul sum. Hence, the answer is false.
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 1<=arr.size()<=105
// 1<=arr[i]<=106

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags

int n = arr.size();

// If only one element is present
if (n == 1)
    return false;

// Taking two variable to store left and right sum

int sumL = arr[0], sumR = arr[n - 1];

// if only two elements then check if both are equal or not
if (n == 2)
    return sumL == sumR;

int i = 1, j = n - 2;

// loop from second to second last element
while (i < j)
{

    // if left sum is greater - add value from right into right sum
    if (sumL > sumR)
        sumR += arr[j--];

    // if right sum is greater - push into left.
    else if (sumR > sumL)
        sumL += arr[i++];

    // if both are equal then add 1 element each from left and right
    else
    {
        sumL += arr[i++];
        sumR += arr[j--];
    }
}

// if sum middle element left then check if it can be added to any side
if (i == j)
{
    if (sumL > sumR)
        sumR += arr[j];
    else if (sumL < sumR)
        sumL += arr[i];
    else
        return false;
}

return sumL == sumR;
}

// Max min Height
// HardAccuracy: 72.28%Submissions: 7K+Points: 8
// Participate in Monthly Hiring Challenge conducted by GeeksforGeeks !!

// You have a garden with n flowers lined up in a row. The height of ith flower is ai units. You will water them for k days. In one day you can water w continuous flowers (you can do this only once in a single day). Whenever you water a flower its height increases by 1 unit. You need to maximize the height of the smallest flower all the time.

// Example 1:

// Input:
// n=6
// k=2
// w=3
// a[]={2,2,2,2,1,1}
// Output:
// 2
// Explanation:
// Water last three flowers for first day &
// first three flowers for second day.The
// new heights will be {3,3,3,3,2,2}
// Example 2:

// Input:
// n=2
// k=5
// w=1
// a[]={5,8}
// Output:
// 9
// Explanation:
// For the first four days water the first flower then
// water the last flower once.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maximizeMinHeight() which takes the array a[], its size N, integer K, and an integer W as input parameters and returns the maximum height possible for the smallest flower.

// Expected Time Complexity: O(NLogN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n<= 105
// 1<=w<=n
// 1<=k<=105
// 1 <= a[i] <= 109

// View Bookmarked Problems

class Solution
{
public:
    long long int maximizeMinHeight(int n, int k, int w, vector<int> &a)
    {
        // code here
        long long int l = 1, r = 1e10, ans = 0;
        int b[n];

        while (l <= r)

        {

            long long int m = (l + r) / 2;
            memset(b, 0, sizeof(b));
            long long int sum = 0, d = 0;

            for (int i = 0; i < n; i++)

            {

                sum -= b[i];

                long long int y = a[i] + sum;

                if (y < m)

                {

                    d += m - y;
                    sum += m - y;
                    if (i + w < n)
                        b[i + w] += m - y;
                }

                if (d > k)

                    break;
            }

            if (d > k)

                r = m - 1;

            else if (d <= k)

            {

                ans = m;
                l = m + 1;
            }
        }

        return ans;
    }
};

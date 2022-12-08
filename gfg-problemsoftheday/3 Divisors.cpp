// 3 Divisors
// MediumAccuracy: 11.17%Submissions: 28495Points: 4
// You are given a list of q queries and for every query, you are given an integer N.  The task is to find how many numbers(less than or equal to N) have number of divisors exactly equal to 3.

// Example 1:

// Input:
// q = 1
// query[0] = 6
// Output:
// 1
// Explanation:
// There is only one number 4 which has
// exactly three divisors 1, 2 and 4 and
// less than equal to 6.
// Example 2:

// Input:
// q = 2
// query[0] = 6
// query[1] = 10
// Output:
// 1
// 2
// Explanation:
// For query 1 it is covered in the
// example 1.
// query 2: There are two numbers 4 and 9
// having exactly 3 divisors and less than
// equal to 10.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function threeDivisors() which takes an integer q and a list of integer of size q as input parameter and returns the list containing the count of the numbers having exactly 3 divisors for each query.

// Expected Time Complexity: O(q*N*log(log(N)))
// Expected Auxiliary Space: O(N), where N is min(10^6,N)

// Constraints :
// 1 <= q <= 10^3
// 1 <= query[i] <= 10^12

// View Bookmarked Problems

class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here

        vector<long long int> v;

        long long int p = 999990;

        long long int arr[p] = {0};

        long long int i, j;

        for (i = 2; i <= sqrt(p); i++)

        {

            if (arr[i] == 0)
            {

                for (j = i * i; j <= p; j += i)

                    arr[j] = 1;
            }
        }

        for (i = 2; i <= p; i++)

        {

            if (arr[i] == 0)

                v.push_back(i); // vec of prime no.
        }

        vector<int> fin;

        for (i = 0; i < query.size(); i++)

        {

            long long int target = query[i], c = 0, index;

            if (target == 2 || target == 1)

                fin.push_back(0);

            else if (target == 3)

                fin.push_back(0);

            else
            {

                long long int l = 0, r = v.size() - 1, m = (l + r) / 2;

                while (l <= r)

                {

                    if (v[m] * v[m] < target)

                    {

                        c++;

                        index = m;

                        l = m + 1;
                    }

                    else if (v[m] * v[m] == target)

                    {

                        c++;

                        index = m;

                        break;
                    }

                    else if (v[m] * v[m] > target)

                    {

                        r = m - 1;
                    }

                    m = (l + r) / 2;
                }

                if (c > 0)

                    fin.push_back(index + 1);
            }
        }

        return fin;
    }
};

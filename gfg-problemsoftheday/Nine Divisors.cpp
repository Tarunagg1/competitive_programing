// Nine Divisors
// MediumAccuracy: 55.2%Submissions: 1221Points: 4
// Find the count of numbers less than equal to N having exactly 9 divisors.

// Example 1:

// Input:
// N = 100
// Output:
// 2
// Explanation:
// The two numbers which have
// exactly 9 divisors are 36 and 100.
// Example 2:

// Input:
// N = 1000
// Output:
// 8
// Explanation:
// The numbers are:
// 36 100 196 225 256 441 484 676

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function nineDivisors() which takes an integer N as an input parameter and returns the total number of elements from 1 to N inclusive, that have exactly 9 divisors.

// Expected Time Complexity: O(sqrt(N))
// Expected Auxiliary Space:  O(sqrt(N))

// Constraints:
// 1<=N<=1010

#define ll long long
class Solution
{
public:
    long long int nineDivisors(long long int n)
    {
        ll m = sqrt(n);
        vector<int> isPrime(m + 1, true);
        for (ll i = 2; i * i <= m; i++)
            for (ll j = i * i; j <= m; j += i)
                isPrime[j] = false;

        vector<ll> primes;
        for (int i = 2; i <= m; i++)
            if (isPrime[i])
                primes.push_back(i);

        ll fac1 = sqrt(sqrt(sqrt(n)));
        ll ans = upper_bound(primes.begin(), primes.end(), fac1) - primes.begin();

        ans = max(ans, 0ll);

        for (ll i = 0; i < primes.size(); i++)
        {
            for (ll j = i + 1; j < primes.size(); j++)
            {
                if (primes[i] * primes[j] > m)
                    break;
                ans++;
            }
        }
        return ans;
    }
};

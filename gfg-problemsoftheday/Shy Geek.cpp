// Shy Geek
// MediumAccuracy: 59.06%Submissions: 3K+Points: 4
// Lamp
// You can earn more Geekbits by participating in GFG Weekly Coding Contest

// Geek went to buy some chocolates from a nearby shop with k coins in his pocket. He found that the shop contains n chocolates which are arranged in sorted order (increasing) of their prices.

// Now geek wants to taste costlier chocolates so he decided that he will buy the costliest chocolate (of course among the ones that he can afford) till there exists at least one type of chocolate he can afford. You may assume that there is an infinite supply of chocolates in the shop Geek visited.

// As you know, Geek is a shy person and hence he will enquire about the prices of the chocolates at most 50 times from the shopkeeper. Now, your task is to find the number of chocolates he had enjoyed.

// Note: If you call the Shop.get function more than 50 times it will return -1. Price of chocolates are pairwise distinct.

// Example 1:

// Input:
// 3 5
// 2 4 6

// Output:
// 1

// Explanation: The prices of chocolates are [2, 4, 6] and Geek had 5 coins with him. So he can only buy chocolate that costs 4 coins (since he always picks the costliest one).
// Example 2:

// Input:
// 4 9
// 1 2 3 4

// Output:
// 3

// Explanation: The prices of chocolates are [1, 2, 3, 4] and Geek had 9 coins with him. So he can buy two chocolates that cost 4 coins. Thereafter, he had only 1 coin with him, hence he will have 1 more chocolate (that costs 1 coin).
// Your Task:
// Return the number of chocolates geeks had eaten. Use the get(int i) function to inquire about the price of the i'th chocolate.
// Note that, you can only call that function 50 times after which it will return -1. Test cases are generated such that the answer can always be found.

// Expected Time Complexity: O(logN)
// Expected Auxiliary Space: O(logN)

// Constraints:
// 0 < n < 105
// 0 < priceOfChocolate < = 107
// 0 < k <= 1012

// View Bookmarked Problems

class Solution
{
public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k)
    {
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        if (k == 0)
            return 0;
        long long ans = 0;
        long long low = 0, high = n - 1;
        long long mid_val = -1;
        long long mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            mid_val = shop.get(mid);
            if (mid_val == k)
            {
                k = 0;
                ans++;
                return ans;
            }
            else if (mid_val < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (mid_val == -1)
            return 0;
        if (mid_val > k && mid > 0)
        {
            int cur = shop.get(mid - 1);
            ans += k / cur;
            k -= (k / cur) * cur;
        }
        else if (mid_val > k && mid == 0)
            return 0;
        else if (mid_val < k)
        {
            ans += k / mid_val;
            k -= (k / mid_val) * mid_val;
        }
        return ans + find(mid, k);
    }
};

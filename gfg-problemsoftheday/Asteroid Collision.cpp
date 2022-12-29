// Asteroid Collision
// MediumAccuracy: 29.33%Submissions: 450+Points: 4
// Lamp
// Land your Dream Job with Mega Job-a-thon. Register Now!

// We are given an integer array asteroids of size N representing asteroids in a row. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are of same size, both will explode. Two asteroids moving in the same direction will never meet.

// Example 1:

// Input:
// N = 3
// asteroids[ ] = {3, 5, -3}
// Output: {3, 5}
// Explanation: The asteroid 5 and -3 collide resulting in 5. The 5 and 3 never collide.
// Example 2:

// Input:
// N = 2
// asteroids[ ] = {10, -10}
// Output: { }
// Explanation: The asteroid -10 and 10 collide exploding each other.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function asteroidCollision() which takes the array of integers asteroids and N as parameters and returns the state of asteroids after all collisions.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 105
// -1000 ≤ asteroidsi  ≤ 1000
// asteroids[i]!=0

class Solution
{
public:
    vector<int> asteroidCollision(int N, vector<int> &v)
    {
        // code here
        vector<int> q;
        q.push_back(v[0]);
        for (int i = 1; i < v.size(); i++)
        {
            if (q.empty() == true || v[i] > 0 || q.back() < 0)
            {
                q.push_back(v[i]);
                continue;
            }
            else if (abs(q.back()) == abs(v[i]))
            {
                q.pop_back();
            }
            else
            {
                while (q.empty() == false && abs(q.back()) < abs(v[i]) && q.back() > 0)
                {
                    q.pop_back();
                }
                if (q.empty() == true)
                {
                    q.push_back(v[i]);
                }
                else if (q.back() < 0)
                {
                    q.push_back(v[i]);
                }
                else if (abs(q.back()) == abs(v[i]))
                {
                    q.pop_back();
                }
            }
        }
        return q;
    }
};

// Avoid Explosion
// HardAccuracy: 76.99%Submissions: 3K+Points: 8
// Lamp
// Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

// Geek is a chemical scientist who is performing an experiment to find an antidote to a poison. The experiment involves mixing some solutions in a flask. Based on the theoretical research Geek has done, he came up with an n * 2 array 'mix', where mix[i] = {X, Y} denotes solutions X and Y that needs to be mixed.

// Also, from his past experience, it has been known that mixing some solutions leads to an explosion and thereby completely ruining the experiment. The explosive solutions are also provided as a m * 2 array 'danger' where danger[i] = {P, Q} denotes that if somehow solutions P and Q get into the same flask it will result in an explosion.

// Help the Geek by returning an array 'answer' of size n, where answer[i] = "Yes" if it is safe to mix solutions in 'mix[i]' or else answer[i] = "No".

// Note: Geek should follow the order of mixing of solutions as it is in 'mix' otherwise the antidote will be ineffective. Also, Geek will not mix the solutions in 'mix[i]' once he gets to know that mixing them will result in an explosion.

// Example 1:

// Input:
// n = 5, m = 2
// mix = {{1, 2}, {2, 3}, {4, 5}, {3, 5}, {2, 4}}
// danger = {{1, 3}, {4, 2}}

// Output:
// answer = {"Yes", "No", "Yes", "Yes", "No"}

// Explanation:
// Mixing the first solution(1 and 2) of 'mix' do not result in any kind of explosion hence answer[0] is "Yes", while mixing 2 and 3 is not allowed because it will result in an explosion as 1 and 3 would be in same solution hence we have returned "No" as the answer for it. Mixing the third solution(4 and 5) and 4th solution(3 and 5) of 'mix' do not result in any kind of explosion hence answer[2] and answer[3] is "Yes". While mixing 2 and 4 is not allowed because it will result in an explosion hence we have returned "No" as the answer for it.
// Example 2:

// Input:
// n = 3, m = 2
// mix = {{1, 2}, {2, 3}, {1, 3}}
// danger = {{1, 2}, {1, 3}}

// Output:
// answer = {"No", "Yes", "No"}

// Explanation:
// Mixing solutions 1 and 2 is dangerous hence
// answer[0] = "No", but solutions 2 and 3 can
// be mixed without any problem therefore answer[1]
// = "Yes". Again, mixing solutions 1 and 3 is
// dangerous due to which answer[2] = "No".

// Your Task:

// You don't need to read input or print anything. Complete the function avoidExplosion() which takes the mix array, its size, danger array, and its size as input parameters and returns the result array or list.

// Expected Time Complexity: O(n*m*log(n))
// Expected Space Complexity: O(n)

// Constraints:

// 0 < n < 1000

// 0 < m < 1000

// 1 <= mix[i][0], mix[i][1] <= n

// 1 <= danger[i][0], danger[i][1] <= n

// mix[i][0] != mix[i][1]

// danger[i][0] != danger[i][1]

// View Bookmarked Problems

class Solution
{
public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m)
    {

        vector<int> ds(n);
        for (int i = 0; i < n; i++)
            ds[i] = i;

        vector<string> res;
        for (int i = 0; i < n; i++)
        {
            int x = mix[i][0] - 1, y = mix[i][1] - 1;
            int fx = find(x, ds), fy = find(y, ds);
            bool is_safe = true;
            for (int j = 0; j < m; j++)
            {
                int p = danger[j][0] - 1, q = danger[j][1] - 1;
                int fp = find(p, ds), fq = find(q, ds);
                if ((fx == fp && fy == fq) || (fx == fq && fy == fp))
                {
                    is_safe = false;
                    break;
                }
            }
            res.push_back(is_safe ? "Yes" : "No");
            if (is_safe)
                ds[fx] = fy;
        }

        return res;
    }

private:
    int find(int x, vector<int> &ds)
    {
        if (ds[x] != x)
            ds[x] = find(ds[x], ds);
        return ds[x];
    }
};

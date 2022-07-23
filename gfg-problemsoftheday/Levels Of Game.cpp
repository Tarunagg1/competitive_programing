// Levels Of Game
// EasyAccuracy: 24.96%Submissions: 320Points: 2
// You are playing a game. At each level of the game, you have to choose one of the roads to go to the next level. Initially, you have h amount of health and m amount of money.
// If you take the first road then your health increases by 3 and money increase by 2. If you take the second road then your health decreases by 5 and money decrease by 10. If you take the third road then health decreases by 20 and money increase by 5.
// You have to tell what is the maximum level you can reach up to under the constraints that in no two consecutive levels you can select the same road twice and once your health or money becomes <= 0 game ends(that level is not counted).

// Example 1:

// Input:
// H=2
// M=10
// Output:
// 1
// Explanation:
// For the first level, we can only choose the first road.
// Now we cannot move ahead anymore.
// Example 2:

// Input:
// H=20
// M=8
// Output:
// 5
// Explanation:
// Go like this:- R1(23,10)->R3(3,15)->R1(6,17)->
// R2(1,7)->R1(4,9)-> game ends as we cannot choose
// any more roads.
 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function maxLevel() which takes in the health and the money as input and returns the maximum level that can be reached by you.

 

// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N*N)

 

// Constraints:
// 1 <= H,M<=1000. 


class Solution{
    public:
          map <pair<int, int>, int> dp;
        int maxLevel(int h,int m)
        {
            // code here
            if (dp[make_pair(h, m)] > 0)
                return dp[make_pair(h, m)];
            int res = 0, tmp_h = h, tmp_m = m;
            while (1) {
                res++;
                h += 3, m += 2;
                if (h <= 5)
                    break;
                else if (h > 5 && h <= 20) {
                    if (m <= 10) 
                        break;
                    res++;
                    h -= 5, m -= 10;
                }
                else if (h > 20) {
                    res++;
                    if (m <= 10)
                        h -= 20, m += 5;
                    else {
                        res += max(maxLevel(h - 5, m - 10), maxLevel(h - 20, m + 5));
                        break;
                    }
                }
            }
            return dp[make_pair(tmp_h, tmp_m)] = res;
        }
};





































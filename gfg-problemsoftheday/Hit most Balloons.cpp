// Hit most Balloons 
// Medium Accuracy: 61.93% Submissions: 1455 Points: 4
// You are given an infinite two-dimensional grid. There are N balloons placed at certain coordinates of the grid. You have an arrow with yourself, which you will be using to shoot the balloons. You can select any point on the grid as your starting point and any point on the grid as the target point. When you fire the arrow, all ballons lying on the shortest path between the starting point and target point will be burst. Given the coordinates of the N ballons in an array arr, your task is to find out the maximum number of balloons that you can fire in one arrow shot.

// Example 1:

// Input:
// N = 3
// arr[] = {{1, 2}, {2, 3}, {3, 4}}
// Output:
// 3
// Explanation:
// If you position yourself at point (1,2)
// and fire the arrow aiming at the point (3,4).
// Then all the balloons will burst.
// Example 2:

// Input: 
// N = 3
// arr[] = {{2,2}, {0,0}, {1,2}} 
// Output:
// 2
// Explanation: 
// If you position yourself at point (2,2)
// and fire the arrow aiming at the point (0,0).
// Then the two balloons present at the two points
// will burst.
// Your Task:
// Complete the function mostBalloons() which takes the integers N and the array arr as the input parameters, and returns the maximum number of balloons that can be burst using one arrow.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 103
// -109 ≤ arr[i][j] ≤ 109

// View Bookmarked Problems
// Company Tags



class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int ans = INT_MIN;
        for(int i = 0; i < N; i++){
            unordered_map<double, int>mp;
            int dups = 1, t_ans = INT_MIN;
            int infs = 0;
            
            for(int j=i+1; j<N; j++){
                int dx = arr[i].first - arr[j].first;
                int dy = arr[i].second - arr[j].second;
                if(dx == 0 && dy == 0){
                    dups++;
                }
                else if(dx == 0){
                    infs++;
                    t_ans = max(t_ans, infs);
                }
                else{
                    mp[dy/double(dx)]++;
                    t_ans = max(t_ans, mp[dy/double(dx)]);
                }
            }
            ans = max(ans, t_ans + dups);
        }
        return ans;
    }
};






















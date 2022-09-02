// Minimum Cost to cut a board into squares
// MediumAccuracy: 57.91%Submissions: 2715Points: 4
// A board of length M and width N is given. The task is to break this board into M * N squares such that cost of breaking is minimum. The cutting cost for each edge will be given for the board in two arrays X[] and Y[]. In short, you need to choose such a sequence of cutting such that cost is minimized. Return the minimized cost.

// Example 1:

// Input:
// M = 6. N = 4
// X[] = {2, 1, 3, 1, 4}
// Y[] = {4, 1, 2}
// Output: 42
// Explanation:

// For above board optimal way to cut into square is:
// Total minimum cost in above case is 42. It is
// evaluated using following steps.
// Initial Value : Total_cost = 0
// Total_cost = Total_cost + edge_cost * total_pieces
// Cost 4 Horizontal cut:      Cost = 0 + 4*1 = 4
// Cost 4 Vertical cut:        Cost = 4 + 4*2 = 12
// Cost 3 Vertical cut:        Cost = 12 + 3*2 = 18
// Cost 2 Horizontal cut:      Cost = 18 + 2*3 = 24
// Cost 2 Vertical cut:        Cost = 24 + 2*3 = 30
// Cost 1 Horizontal cut:      Cost = 30 + 1*4 = 34
// Cost 1 Vertical cut:        Cost = 34 + 1*4 = 38
// Cost 1 Vertical cut:        Cost = 38 + 1*4 = 42

// Example 2:

// Input:
// M = 4, N = 4
// X[] = {1, 1, 1}
// Y[] = {1, 1, 1}
// Output: 15
// Explanation:

// For above board optimal way to cut into square is:
// Total minimum cost in above case is 15.
// It is evaluated using following steps.
// Initial Value :
// Total_cost = 0 Total_cost = Total_cost + edge_cost * total_pieces
// Cost 1 Horizontal cut: Cost = 0 + 1*1 = 1
// Cost 1 Horizontal cut: Cost = 1 + 1*1 = 2
// Cost 1 Horizontal cut: Cost = 2 + 1*1 = 3
// Cost 1 Vertical cut:   Cost = 3 + 1*3 = 6
// Cost 1 Vertical cut:   Cost = 6 + 1*3 = 9
// Cost 1 Vertical cut: Cost = 9 + 1*3 = 12
// Cost 1 Vertical cut:   Cost = 12 + 1*3 = 15

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minimumCostOfBreaking() which takes a string S and returns an integer as output.

// Expected Time Complexity: O(NlogN + MlogM)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 <= N, M <= 105

class Solution
{
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n)
    {
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        int i = 0, j = 0;
        int ans = 0;
        while (i < x.size() and j < y.size())
        {
            if (x[i] > y[j])
            {
                ans += (j + 1) * x[i];
                i++;
            }
            else
            {
                ans += (i + 1) * y[j];
                j++;
            }
        }
        while (i < x.size())
        {
            ans += (j + 1) * x[i];
            i++;
        }
        while (j < y.size())
        {
            ans += (i + 1) * y[j];
            j++;
        }
        return ans;
    }
};

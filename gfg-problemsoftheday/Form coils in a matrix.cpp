// Form coils in a matrix
// Medium Accuracy: 89.37% Submissions: 523 Points: 4
// Given a positive integer n that represents dimensions of a 4n x 4n matrix with values from 1 to 4*n*4*n filled from left to right and top to bottom. Your task is to form two coils from matrix and print the coils.

// Follow the given examples for better understanding.

// Example 1:

// Input:
// n = 1
// Output:
// 10 6 2 3 4 8 12 16
// 7 11 15 14 13 9 5 1
// Explanation:
// The matrix is
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
// So, the two coils are as given in the Ouput.
// Example 2:

// Input:
// n = 2
// Output:
// 36 28 20 21 22 30 38 46
// 54 53 52 51 50 42 34 26
// 18 10 2 3 4 5 6 7 8
// 16 24 32 40 48 56 64

// 29 37 45 44 43 35 27 19
// 11 12 13 14 15 23 31 39
// 47 55 63 62 61 60 59 58
// 57 49 41 33 25 17 9 1
// Explanation:

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function formCoils() which takes an Integer n as input and returns a vector of two vectors representing coil1 and coil2.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 <= n <= 20

class Solution
{
public:
    bool inBoard(int x, int y, int n)
    {
        if (x >= n || y >= n || x < 0 || y < 0)
            return 0;
        return 1;
    }

    vector<vector<int>> formCoils(int n)
    {
        // code here
        n = 4 * n;
        vector<vector<int>> V;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
            {
                tmp.push_back(-1);
            }
            V.push_back(tmp);
        }
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                V[i][j] = cnt;
                cnt++;
            }
        }
        int XI = n / 2 - 1;
        int YI = n / 2;
        vector<int> ans1, ans2;
        vector<string> direction = {"down", "left", "up", "right"};
        int dir = 0;
        ans1.push_back(V[XI][YI]);
        int steps = 2;
        int incSteps = 0;
        while (V[XI][YI] != 1)
        {
            for (int i = 0; i < steps; i++)
            {
                if (V[XI][YI] == 1)
                    break;
                if (direction[dir] == "down")
                    XI++;
                else if (direction[dir] == "left")
                    YI--;
                else if (direction[dir] == "up")
                    XI--;
                else if (direction[dir] == "right")
                    YI++;
                if (inBoard(XI, YI, V.size()))
                    ans1.push_back(V[XI][YI]);
            }
            dir = (dir + 1) % 4;
            incSteps++;
            if ((incSteps % 2) == 0)
                steps = steps + 2;
        }
        XI = n / 2;
        YI = n / 2 - 1;
        direction = {"up", "right", "down", "left"};
        steps = 2;
        incSteps = 0;
        dir = 0;
        ans2.push_back(V[XI][YI]);
        while (V[XI][YI] != n * n)
        {
            for (int i = 0; i < steps; i++)
            {
                if (V[XI][YI] == n * n)
                    break;
                if (direction[dir] == "down")
                    XI++;
                else if (direction[dir] == "left")
                    YI--;
                else if (direction[dir] == "up")
                    XI--;
                else if (direction[dir] == "right")
                    YI++;
                if (inBoard(XI, YI, V.size()))
                    ans2.push_back(V[XI][YI]);
            }
            dir = (dir + 1) % 4;
            incSteps++;
            if ((incSteps % 2) == 0)
                steps = steps + 2;
        }
        V.clear();
        V.push_back(ans2);
        V.push_back(ans1);
        return V;
    }
};

// Maximum Connected group
// Difficulty: HardAccuracy: 49.48%Submissions: 22K+Points: 8
// You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent to each other and both have the same value.

// Examples :

// Input: grid = [1, 1]
//              [0, 1]
// Output: 4
// Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
// [1, 1]
// [1, 1]
// Input: grid = [1, 0, 1]
//              [1, 0, 1]
//              [1, 0, 1]
// Output: 7
// Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
// [1, 0, 1]
// [1, 0, 1]
// [1, 1, 1]
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 <= size of the grid<= 500
// 0 <= grid[i][j] <= 1

class DSU
{
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int par1 = find(x);
        int par2 = find(y);
        if (par1 != par2)
        {
            if (size[par1] > size[par2])
            {
                size[par1] += size[par2];
                parent[par2] = par1;
            }
            else
            {
                size[par2] += size[par1];
                parent[par1] = par2;
            }
        }
    }

    int getSize(int x)
    {
        return size[find(x)];
    }
};

class Solution
{
public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        DSU dsu(n * m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    int node = i * m + j;
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj])
                        {
                            int temp = ni * m + nj;
                            dsu.unite(node, temp);
                        }
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    // all adjacent can be connected
                    // we only want unique componenets
                    unordered_set<int> baap;
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj])
                        {
                            int temp = ni * m + nj;
                            baap.insert(dsu.find(temp));
                        }
                    }
                    int total_sz = 1;
                    for (auto it : baap)
                    {
                        total_sz += dsu.getSize(it);
                    }
                    ans = max(ans, total_sz);
                }
                else
                {
                    // jodya pachi pan jaruri nathi ae savthi motu comp hase
                    ans = max(ans, dsu.getSize(i * m + j));
                }
            }
        }

        return ans;
    }
};

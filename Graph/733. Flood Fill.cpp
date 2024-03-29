// 733. Flood Fill
// Easy

// 3197

// 330

// Add to List

// Share
// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

// Return the modified image after performing the flood fill.

// Example 1:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
// Example 2:

// Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
// Output: [[2,2,2],[2,2,2]]

// Constraints:

// m == image.length
// n == image[i].length
// 1 <= m, n <= 50
// 0 <= image[i][j], newColor < 216
// 0 <= sr < m
// 0 <= sc < n
// Accepted
// 324,184
// Submissions
// 565,942

class Solution
{
public:
    bool isValid(vector<vector<int>> &image, int sr, int sc, int n, int m, int color)
    {
        if (sr >= 0 && sr < n && sc >= 0 && sr < m && image[sr][sc] == color)
            return true;
        return false;
    }

    void floodFillIRec(vector<vector<int>> &image, int sr, int sc, int n, int m, int color, int newColor)
    {
        image[sr][sc] = newColor;

        if (isValid(image, sr + 1, sc, n, m, color))
        {
            floodFillIRec(image, sr + 1, sc, n, m, color, newColor);
        }
        if (isValid(image, sr - 1, sc, n, m, color))
        {
            floodFillIRec(image, sr - 1, sc, n, m, color, newColor);
        }
        if (isValid(image, sr, sc + 1, n, m, color))
        {
            floodFillIRec(image, sr, sc + 1, n, m, color, newColor);
        }
        if (isValid(image, sr, sc - 1, n, m, color))
        {
            floodFillIRec(image, sr, sc - 1, n, m, color, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        int color = image[sr][sc];

        floodFillIRec(image, sr, sc, n, m, color, newColor);

        return image;
    }
};

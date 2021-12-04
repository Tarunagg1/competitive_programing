
void interchange(vector<vector<int>> &matrix, int c)
{

    // Your code here
    int row = matrix.size();
    int size = matrix[0].size();

    for (int i = 0; i < (row / 2); i++)
    {
        for (int j = 0; j < col; j++)
        {
            swap(matrix[i][j], matrix[row - 1 - i][j]);
        }
    }
}
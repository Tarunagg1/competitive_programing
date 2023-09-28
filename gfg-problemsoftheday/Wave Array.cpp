class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int> &arr)
    {

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 1)
            {
                swap(arr[i], arr[i - 1]);
            }
        }

        // Your code here
    }
};
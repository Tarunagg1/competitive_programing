// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// Chef has two positive integers A and B. He can tamper with them by choosing a digit in the decimal representation of A and a digit in the decimal representation of B and swapping these digits. This operation may be performed at most once.

// Find the maximum possible sum of the resulting numbers which Chef can obtain.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first and only line of each test case contains two space-separated integers A and B.
// Output
// For each test case, print a single line containing one integer ― the maximum sum.

// Constraints
// 1≤T≤1,000
// 1≤A,B≤99
// Sample Input 1
// 3
// 13 82
// 9 24
// 20 30
// Sample Output 1
// 104
// 96
// 50
// Explanation
// Example case 1: Swapping the digits 1 (from 13) and 2 (from 82) gives us 23 and 81. Their sum 23+81=104 is the maximum possible sum.

// Example case 3: Swapping is not needed as the original numbers have the maximum possible sum.

#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int a1 = a / 10;
        int a2 = a % 10;

        int b1 = b / 10;
        int b2 = b % 10;

        int max = a + b;

        if (a1 != 0 && b1 != 0)
        {
            int x = a1 * 10 + b1 + a2 * 10 + b2;
            int y = a1 * 10 + b2 + b1 * 10 + a2;
            int z = b2 * 10 + a2 + b1 * 10 + a1;

            if (max < x)
                max = x;
            else if (max < y)
                max = y;
            else
                max = z;
            cout << max << endl;
        }
        else if (a1 != 0 && b == 0)
        {
            int x = b1 + a2 * 10 + b2;
            int y = b2 + b1 * 10 + a2;

            if (max < x)
                max = x;
            if (max < y)
                max = y;
            cout << max << endl;
        }
        else
        {
            cout << max << endl;
        }
    }

    return 0;
}

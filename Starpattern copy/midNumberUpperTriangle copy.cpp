#include <iostream>

using namespace std;

//    1
//   121
//  12321
// 1234321

int main()
{
    int n = 5;
    int k;

    for (int i = 1; i <= 4; i++)
    {
        k = 1;
        for (int j = 1; j <= 7; j++)
        {
            if (j >= 5 - i && j <= 3 + i)
            {
                cout << k;
                if (j < 4)
                    k++;
                else
                    k--;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        k = 1;
    }
}

#include <iostream>

using namespace std;

// 1
// 3*2
// 4*5*6
// 10*9*8*7
// 11*12*13*14*15

int main()
{
    int k = 0, p;
    for (int i = 1; i <= 5; i++)
    {
        if (i % 2 == 1)
            k = k + 1;
        else
            k = k + i;
        p = k;
        for (int j = 1; j <= 9; j++)
        {
            if (j <= 2 * i - 1)
            {
                if (j % 2 == 0)
                {
                    cout << "*";
                }
                else
                {
                    cout << p;
                    if (i % 2)
                    {
                        p++;
                        k++;
                    }
                    else
                        p--;
                }
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

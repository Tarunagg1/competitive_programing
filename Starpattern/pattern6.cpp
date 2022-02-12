#include <iostream>

using namespace std;

//     1
//    A  B
//  1  2  3
// A  B  C  D

int main()
{
    int k;
    for (int i = 1; i <= 5; i++)
    {
        k = 1;
        for (int j = 1; j <= 7; j++)
        {
            if (j > 5 - i && j <= 3 + i)
            {
                if (k)
                    cout << "*";
                else
                    cout << " ";
                k = 1 - k;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

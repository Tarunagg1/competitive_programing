#include <iostream>

using namespace std;

// 1
// 62
// 1073
// 131184
// 15141265

int main()
{
    int p, k = 1;
    for (int i = 1; i <= 5; i++)
    {
        p = k;
        for (int j = 1; j <= 8; j++)
        {
            if (j <= i)
            {
                cout << p;
                p = p - (5 - i + j);
            }
            else
            {
                cout << " ";
            }
        }
        k = k + 1 + 5 - i;
        cout << endl;
    }
}

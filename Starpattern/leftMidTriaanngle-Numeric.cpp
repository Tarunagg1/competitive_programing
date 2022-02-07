#include <iostream>

using namespace std;

//     1
//    12
//   123
//  1234
// 12345
//  1234
//   123
//    12
//     1

int main()
{
    int k=0;
    int m=0;
    for (int i = 1; i <= 9; i++)
    {
        m=1;
        i<=5 ? k++ : k--;
        for (int j = 1; j <= 5; j++)
        {
            if (j>=6-k)
            {
                cout <<m;
                m++;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

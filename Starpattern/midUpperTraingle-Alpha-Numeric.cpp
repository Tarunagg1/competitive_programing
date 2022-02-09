#include <iostream>

using namespace std;

//    A1
//   AB12
//  ABC123
// ABCD1234

int main()
{
    char c ='A';
    int num = 1;
    for (int i = 1; i <= 4; i++)
    {
        c='A';
        for (int j = 1; j <= 8; j++)
        {
            if (j>=5-i && j<=4+i)
            {
                if(j == 5){
                    c='1';
                }
                cout << c;
                c++;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}




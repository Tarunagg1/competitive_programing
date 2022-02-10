#include <iostream>

using namespace std;

//    A1
//   AB1A
//  ABC1AB
// ABCD1ABC

int main()
{
    char c ='A';
    int num = 1;
    for (int i = 1; i <= 4; i++)
    {
        c='A';
        for (int j = 1; j <= 7; j++)
        {
            if (j>=5-i && j<=3+i)
            {
                if(j == 4){
                    c='1';
                }
                if(j == 5){
                    c='A';
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




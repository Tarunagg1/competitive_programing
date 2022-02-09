#include <iostream>

using namespace std;

//    A
//   ABA
//  ABCBA
// ABCDCBA

int main()
{
    char c ='A';
    for (int i = 1; i <= 4; i++)
    {    
        c='A';
        for (int j = 1; j <= 7; j++)
        {
            if (j>=5-i && j<=3+i)
            {
                cout << c;
                if(j<4){
                    c++;
                }else{
                    c--;
                }
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}




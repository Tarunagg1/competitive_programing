#include <iostream>

using namespace std;

//   ABCDCBA
//   ABC CBA
//   AB   AB
//   A     A

int main()
{
    char k;

    for (int i = 1; i <= 4; i++)
    {
        k='A';
        for (int j = 1; j <= 7; j++)
        {
            if (j <= 5 - i || j >= 3 + i)
            {
                cout << k;
                if(j < 4){
                    k++;
                }else{
                    k--;
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




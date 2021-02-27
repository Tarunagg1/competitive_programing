/* 
Phone Prices Problem Code: S10E
Add problem to Todo list
Submit

 
Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
Chef wants to buy a new phone, but he is not willing to spend a lot of money. Instead, he checks the price of his chosen model everyday and waits for the price to drop to an acceptable value. So far, he has observed the price for N days (numbere 1 through N); for each valid i, the price on the i-th day was Pi dollars.

On each day, Chef considers the price of the phone to be good if it is strictly smaller than all the prices he has observed during the previous five days. If there is no record of the price on some of the previous five days (because Chef has not started checking the price on that day yet), then Chef simply ignores that previous day ― we could say that he considers the price on that day to be infinite.

Now, Chef is wondering ― on how many days has he considered the price to be good? Find the number of these days.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers P1,P2,…,PN.
Output
For each test case, print a single line containing one integer ― the number of days with a good price.

Constraints
1≤T≤100
7≤N≤100
350≤Pi≤750 for each valid i
Subtasks
Subtask #1 (30 points): N=7
Subtask #2 (70 points): original constraints

Example Input
1
7
375 750 723 662 647 656 619
Example Output
2
Explanation
Example case 1: Chef considers the price to be good on day 1, because he has not observed any prices on the previous days. The prices on days 2,3,4,5,6 are not considered good because they are greater than the price on day 1. Finally, the price on day 7 is considered good because it is smaller than all of the prices on days 2,3,4,5,6.

*/

#include <iostream>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n+1];
        for(int i=1; i<=n; i++){ cin>>arr[i]; }
        int count = 1;
        for(int i=2; i<=n; i++){
            int price = arr[i];
            if(i == 2){
                if(price < arr[i-1])
                    count++;
            }else if(i == 3){
                if(price < arr[i-1] && price<arr[i-2])
                    count++;
            }else if(i == 4){
                if(price < arr[i-1] && price<arr[i-2] && price < arr[i-3])
                    count++;
            }else if(i == 5){
                if(price < arr[i-1] && price<arr[i-2] && price < arr[i-3] && price<arr[i-4])
                    count++;
            }else{
                if(price < arr[i-1] && price<arr[i-2] && price < arr[i-3] && price<arr[i-4] && price<arr[i-5])
                    count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
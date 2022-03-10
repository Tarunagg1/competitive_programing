// Using seven segment display, you can write down any digit from 0 to 9 using at most seven segments. Given a positive number N and then a string S representing a number of N digits. You have to rearrange the segments in this N digit number to get the smallest possible N digit number. This number can have leading zeros. You can not waste any segment or add any segment from your own. You have to use all of the segments of the given N digits.

// Note: You can refer this diagram for more details



// Example 1:

// Input:
// N = 6
// S = "234567"
// Output:
// 000011
// Explanation:
// 234567 has a total of 28 segments and
// we can rearrange them to form 000011
// which has 28 segments too. 000011 is the
// smallest possible number which can be
// formed on rearrangement.
// Example 2:

// Input:
// N = 3
// S = "011"
// Output:
// 011
// Explanation:
// 011 has a total of 10 segments and this
// is the smallest number with 10 segments.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sevenSegments() which takes an Integer N and a String S of length N as input and returns the smallest possible N digit number which can be made using all of the segments given.

 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1 <= N <= 104

// View Bookmarked Problems
// Topic Tags



int arr[]={6,2,5,5,4,5,6,3,7,5};
    long long int ans=0;
    for(int i=0;i<n;i++)
    ans+=arr[s[i]-'0'];
    ans=ans-2*n;
    string res="";
    for(int i=0;i<n;i++)
    {
        if(ans+2>=6)
        {
            res+="0";
            ans=ans-4;
        }
        else
        res+="1";
    }
    int k=n-1;
    while(ans>0)
    {
        if(ans+2>=7)
        {
            res[k]='8';
            ans=ans-5;
            k--;
            
        }
        else if(ans+2>=5)
        {
            res[k]='2';
            ans=ans-3;
            k--;
        }
        else if(ans+2>=4)
        {
            res[k]='4';
            ans=ans-2;
            k--;
        }
        else
        {
            res[k]='7';
            ans=ans-1;
            k--;
        }
        
    }
    return res;





































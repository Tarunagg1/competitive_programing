// Given a string str and a pattern pat. You need to check whether pattern is present or not in the given string. 

// Input Format: The input line contains T, denoting the number of testcases. Each testcase contains two lines. First line contains string str. Second line contains patter text.

// Output format: For each testcase in new line you have to print the "Present" if found otherwise "Not present".

// User task: You need to complete the function searchPattern() containing string and text as an argument. You don't have to worry about input. 

// Constraints:
// 1 <= T <= 100
// 1 <= |str| <= 30
// 1 <= |text| <= 30

// Sample Input:
// 2
// abcdefh
// bcd
// axzy
// xy

// Sample Output:
// Present
// Not present

// Method 1

bool searchPattern(string str, string pat)
{
    // your code here
    int m = str.size();
    int n = pat.size();
    
    for(int i=0; i<=(m-n); i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(pat[j] == str[j+i]){
                count++;
            }
        }
        if(count == n){
            return 1;
        }
    }
    return 0;
    
}


// Method 2

bool searchPattern(string str, string pat)
{
    // your code here
    int m = str.size();
    int n = pat.size();
    
    for(int i=0; i<=(m-n); i++){
        bool isBool = true;
        for(int j=0; j<n; j++){
            if(pat[j] != str[j+i]){
                isBool = false;
            }
        }
        if(isBool){
            return 1;
        }
    }
    return 0;
    
}



// Problem
// Well, lazy to give a theme or backstory to the question too. So, lets dive into the problem right away!

// You are given N points in xy-plane. Determine the difference between maximum and minimum areas of rectangle formed from these points, with sides parallel to X and Y axes. In case no rectangle can be formed, print -1.

// Note, that the points used in one rectangle, may be used in another rectangle. Also, it is guaranteed that that N points don't have any duplicates. Refer test cases for further explanation.

// Constraints:

// 1 <= N <= 1000

// 0 <= x,y for each point <= 45000

// Input Format:

// First line contains N value.

// Next N lines contain 2 space separated integers - "x y"

// Output Format:

// One line containing the difference or -1, which ever applicable.

// Sample Input
// 6
// 10 0
// 0 10
// 10 2
// 0 0
// 0 2
// 10 10
// Sample Output
// 80
// Time Limit: 1
// Memory Limit: 256
// Source Limit:
// Explanation
// 2 rectangles can be formed here - one with (0,0) (0,10) (10,10) and (10,0) which gives max area of 100; other with (0,0) (0,2) (10,2) and (10,0) which gives min area of 20. Thus the difference is 80.

// Note that - IF points (0,3) and (10,3) existed, then the rectangle with minimum area would have been formed by thrse points along with (0,2) and (10,2) and the min area shall be 10. Thus, our answer becomes 90 in that case.


#include <stdio.h>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
































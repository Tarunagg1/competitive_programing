// Geek in a Maze 
// Hard Accuracy: 47.38% Submissions: 1066 Points: 8
// Lamp Geeks Summer Carnival is LIVE NOW   
// Geek is in a maze of size N * M. Each cell in the maze is made of either '.' or '#'. An empty cell is represented by '.' and an obstacle is represented by '#'. If Geek starts at cell (R, C), find how many different empty cells he can pass through while avoiding the obstacles. He can move in any of the four directions but he can move up at most U times and he can move down atmost D times.

 

// Example 1:

// Input: 
// N = 3, M = 3
// R = 1, C = 0
// U = 1, D = 1
// mat = {{'.', '.', '.'},
//        {'.', '#', '.'},
//        {'#', '.', '.'}}
// Output: 5
// Explanation: Geek can reach 
// (1, 0), (0, 0), (0, 1), (0, 2), (1, 2) 


// Example 2:

// Input: 
// N = 3, M = 4
// R = 1, C = 0
// U = 1, D = 2 
// mat = {{'.', '.', '.'}, 
//        {'.', '#', '.'}, 
//        {'.', '.', '.'},
//        {'#', '.', '.'}} 
// Output: 10
// Explanation: Geek can reach all the 
// cells except for the obstacles.
 

// Your Task:  
// You don't need to read input or print anything. Complete the function numberOfCells() which takes N, M, R, C, U, D and the two dimensional character array mat[][] as input parameters and returns the number of cells geek can visit( If he is standing on obstacle he can not move).


// Constraints:
// 1 ≤ N*M ≤ 106
// mat[i][j] = '#" or '.'
// 0 ≤ R ≤ N-1
// 0 ≤ C ≤ M-1

// View Bookmarked Problems
// Topic Tags

class Solution{
    queue<array<int, 4>> q;
		q.push({r, c, 0, 0});
		mat[r][c] = '1';
		while(!q.empty()){
		    int x = q.front()[0], y = q.front()[1];
		    int up = q.front()[2], down = q.front()[3];
		    q.pop();
		    if(y + 1 < m && mat[x][y + 1] == '.'){
		        q.push({x, y + 1, up, down});
		        mat[x][y + 1] = '1';
		    }
		    if(y - 1 >= 0 && mat[x][y - 1] == '.'){
		        q.push({x, y - 1, up, down});
		        mat[x][y - 1] = '1';
		    }
		    if(x + 1 < n && down != d && mat[x + 1][y] == '.'){
		        q.push({x + 1, y, up, down + 1});
		        mat[x + 1][y] = '1';
		    }
		    if(x - 1 >= 0 && up != u && mat[x - 1][y] == '.'){
		        q.push({x - 1, y, up + 1, down});
		        mat[x - 1][y] = '1';
		    }
		}
		int cnt = 0;
		for(int i = 0;  i < n; i++){
		    for(int j = 0; j < m; j++){
		        if(mat[i][j] == '1') cnt++;
		    }
		}
		return cnt;
}























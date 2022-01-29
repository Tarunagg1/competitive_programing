// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// Ada is training for her match against Magnus Carlsen in the World Chess Championship 2020.

// Ada took a standard chessboard with 8 rows (numbered 1 through 8) and 8 columns (numbered 1 through 8); let's denote a cell in row r and column c by (r,c). Then, Ada placed a bishop in a cell (r0,c0); it is guaranteed that this cell is black. Ada's goal is to move the bishop in such a way that it visits all black cells.

// Remember that a bishop is a piece that moves diagonally ― formally, the bishop may move from a cell (rs,cs) to a cell (rt,ct) if and only if either rs+cs=rt+ct or rs−cs=rt−ct. In such a move, the bishop visits all cells between (rs,cs) and (rt,ct) on this diagonal (inclusive).

// Help Ada find a sequence of at most 64 moves for the bishop such that when the bishop follows this route, it visits all black cells on the chessboard. Note that each cell may be visited multiple times and it is not necessary to return to the starting point.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first and only line of each test case contains two space-separated integers r0 and c0.
// Output
// For each test case:

// First, print a line containing a single integer M (M≤64) ― the number of moves in the bishop's route.
// Then, print M lines. For each i (1≤i≤M), the i-th of these lines should contain two space-separated integers ri and ci, where the route followed by the bishop is (r0,c0)→(r1,c1)→(r2,c2)→…→(rM,cM).
// Constraints
// 1≤T≤32
// 1≤r0,c0≤8
// (r0,c0) is a black cell, i.e. r0+c0 is even
// Subtasks
// Subtask #1 (99 points): r0=c0=1
// Subtask #2 (1 points): original constraints

// Example Input
// 1
// 5 3
// Example Output
// 31
// 3 5
// 4 6
// 7 3
// 5 1
// 1 5
// [26 more lines follow]

// Explanation
// Example case 1: The first five moves of the bishop are shown in the figure below.








































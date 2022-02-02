// Read problem statements in Hindi, Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
// Chef was working on building rail tracks connecting pairs of railway stations in a 2D Cartesian coordinate system. There are N stations on the x-axis, with coordinates x1,x2,…,xN, and M stations on the y-axis, with coordinates y1,y2,…,yM. Chef has completed his task and built a rail track (line segment) between each pair of stations.

// Now, Chef is wondering how many right triangles have the following property: the vertices are stations and the sides are railway tracks between them. Since Chef is busy with his other projects, help him answer this question.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains two space-separated integers N and M.
// The second line contains N space-separated integers x1,x2,…,xN.
// The third line contains M space-separated integers y1,y2,…,yM.
// Output
// For each test case, print a single line containing one integer ― the number of right triangles.

// Constraints
// 1≤T≤5
// 1≤N,M≤105
// |xi|≤105 for each valid i
// |yi|≤105 for each valid i
// the positions of the stations are pairwise distinct
// Subtasks
// Subtask #1 (15 points):

// N,M≤102
// Subtask #2 (25 points):

// N,M≤103
// Subtask #3 (60 points): original constraints

// Sample Input 1
// 2
// 2 2
// -4 2
// 2 -8
// 8 4
// 1 2 3 6 -1 -2 -3 -6
// 6 -6 1 -1
// Sample Output 1
// 1
// 8
// Explanation
// Example case 1: There are no triplets where two stations lie on the x-axis and one triplet where two stations lie on the y-axis, which is ((0,2),(0,−8),(−4,0)).

class solution
{
public:
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>> pq;
    pq.push({0, S});
    dist[S] = 0;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        int a = p.second;
        pq.pop();
        for (int i = 0; i < adj[a].size(); i++)
        {
            int res = adj[a][i][0];
            int w = adj[a][i][1];
            if (w + dist[a] < dist[res])
            {
                dist[res] = dist[a] + w;
                pq.push({-1 * dist[res], res});
            }
        }
    }
    return dist;
}

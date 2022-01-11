#include <iostream>
#include <vector>

using namespace std;

int findNumberOfChocolates(vector<int> s, int d, int m)
{
    int sum[105];

    int count = 0;

    int n = s.size();

    sum[0] = 0;

    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + s[i];
    }

    for (int i = 0; i <= (n - m); i++)
    {
        if (sum[i + m] - sum[i] == d)
            count++;
    }

    return count;
}

int main()
{
    int m, d, n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> d >> m;
    cout << findNumberOfChocolates(v, d, m);
}

//  intput
// 5
// 2 2 1 3 2
// 4 2

// Output
// 2

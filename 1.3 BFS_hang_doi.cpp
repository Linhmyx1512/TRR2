#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 5][n + 5], visited[n + 5] = {};
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }

    q.push(12);
    visited[12] = 1;
    cout << "12 ";
    while (q.empty() == false)
    {
        int s = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (visited[i] == 0 && a[s][i] == 1)
            {
                cout << i << " ";
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
#include <iostream>
using namespace std;

int n, a[100][100];
int visited[100] = {};

void DFS(int u)
{
    cout << u << " ";
    visited[u] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[u][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    DFS(1);
}
#include <iostream>
using namespace std;

int n, visited[100] = {}, a[100][100];

void DFS(int u)
{
    visited[u] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == 0 && a[u][i] == 1)
        {
            DFS(i);
        }
    }
}

void init()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
}

int main()
{
    init();
    int dem = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == 0)
        {
            ++dem;
            DFS(i);
        }
    }
    cout << dem;
}

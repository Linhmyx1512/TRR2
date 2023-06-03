#include <iostream>
using namespace std;

int n, a[100][100], visited[100];

void reInit()
{
    for (int i = 1; i <= n; ++i)
        visited[i] = false;
}

void DFS(int u)
{
    visited[u] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (a[u][i] == 1 && visited[i] == false)
            DFS(i);
    }
}

void Try()
{
    for (int i = 1; i <= n; ++i)
    {
        visited[i] = true;
        for (int j = 1; j <= n; ++j)
        {
            if (j != i)
            {
                DFS(j);
                for (int k = 1; k <= n; ++k)
                {
                    if (visited[k] == false)
                    {
                        cout << i << " ";
                        break;
                    }
                }
                break;
            }
        }
        reInit();
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    Try();
}
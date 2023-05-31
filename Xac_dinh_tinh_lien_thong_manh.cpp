#include <iostream>
#include <queue>
using namespace std;
int n, a[100][100];
int visited[100];

void DFS(int u)
{
    visited[u] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[u][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

bool strongly_Connected()
{
    for (int i = 1; i <= n; i++)
    {
        DFS(i);
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == 0)
                return false;
        }
        for (int j = 1; j <= n; j++)
        {
            visited[j] = 0;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    if (strongly_Connected() == true)
        cout << "strongly connected";
    else
        cout << "not strongly connected";
}
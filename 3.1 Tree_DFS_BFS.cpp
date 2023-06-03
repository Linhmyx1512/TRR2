#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int a[100][100], visited[100], count = 0;
vector<pair<int, int>> t;

void Tree_DFS(int u)
{
    visited[u] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (a[u][i] == 1 && visited[i] == false)
        {
            ++count;
            t.push_back({u, i});
            Tree_DFS(i);
        }
    }
}

void Tree_BFS(int u)
{
    t.clear();
    for (int i = 1; i <= n; ++i)
        visited[i] = false;
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (q.size())
    {
        int s = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (a[s][i] == 1 && visited[i] == false)
            {
                q.push(i);
                t.push_back({s, i});
                visited[i] = true;
            }
        }
    }
}

void display()
{
    if (count == n - 1)
    {
        for (int i = 0; i < t.size(); ++i)
        {
            if (t[i].first > t[i].second)
                swap(t[i].first, t[i].second);
            cout << t[i].first;
            if (t[i].first > 9 || t[i].second > 9)
                cout << " ";
            else
                cout << "  ";
            cout << t[i].second << "\n";
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    Tree_DFS(k);
    cout << "DFS tree\n";
    display();
    Tree_BFS(k);
    cout << "BFS tree\n";
    display();
}
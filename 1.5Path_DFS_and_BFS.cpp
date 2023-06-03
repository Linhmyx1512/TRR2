#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n, s, t, a[100][100], visited[100] = {};
int truoc[100];

void DFS_Path()
{
    stack<int> st;
    st.push(s);
    visited[s] = 1;
    while (st.size())
    {
        int u = st.top();
        st.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (a[u][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                st.push(u);
                st.push(i);
                truoc[i] = u;
                break;
            }
        }
    }
    if (truoc[t] != 0)
    {
        cout << "DFS path: ";
        cout << t << " ";
        int k = truoc[t];
        while (k != s)
        {
            cout << k << " ";
            k = truoc[k];
        }
        cout << s << "\n";
    }
    else
        cout << "no path\n";
    for (int i = 0; i <= n; ++i)
        visited[i] = 0;
    for (int i = 0; i <= n; ++i)
        truoc[i] = 0;
}

void BFS_Path()
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (a[u][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
                truoc[i] = u;
            }
        }
    }
    if (truoc[t] != 0)
    {
        cout << "BFS path: ";
        cout << t << " ";
        int k = truoc[t];

        while (k != s)
        {
            cout << k << " ";
            k = truoc[k];
        }
        cout << s;
    }
}

void init()
{
    cin >> n;
    cin >> s >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
}

int main()
{
    init();
    DFS_Path();
    BFS_Path();
}
#include <iostream>
#include <vector>

using namespace std;

int n, s, a[100][100], d[100], dd[100], truoc[100];

void solve()
{
    int t = n - 1;
    while (t--)
    {
        int x = 9999, u;
        for (int i = 1; i <= n; ++i)
        {
            if (dd[i] == 0 && d[i] < x && d[i] > 0)
            {
                x = d[i];
                u = i;
            }
        }
        dd[u] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (a[u][i] && dd[i] == 0)
            {
                if (d[i] > 0)
                {
                    if (d[i] > d[u] + a[u][i])
                    {
                        d[i] = d[u] + a[u][i];
                        truoc[i] = u;
                    }
                }
                else
                {
                    d[i] = d[u] + a[u][i];
                    truoc[i] = u;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
        dd[i] = 0;
        truoc[i] = s;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[s][i] == 0)
        {
            d[i] = -1;
        }
        else
            d[i] = a[s][i];
    }
    d[s] = 0;
    dd[s] = 1;
    solve();
    for (int i = 1; i <= n; ++i)
    {
        cout << "K/c " << s << " -> " << i << " = ";
        if (d[i] == -1)
        {
            cout << "INF\n";
            continue;
        }

        cout << d[i] << ";     " << i << " <- ";
        int x = truoc[i];
        while (x != s)
        {
            cout << x << " <- ";
            x = truoc[x];
        }
        cout << s << endl;
    }
}
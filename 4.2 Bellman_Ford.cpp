#include <iostream>

using namespace std;

int n, s, a[100][100], truoc[100], dd[100], d[100];

void solve()
{
    int t = n - 2;
    while (t--)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (i != s)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (a[j][i] != 0)
                    {
                        if (d[i] > d[j] + a[j][i])
                        {
                            d[i] = d[j] + a[j][i];
                            truoc[i] = j;
                        }
                    }
                }
            }
        }
    }
}

void init()
{
    cin >> n >> s;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
        truoc[i] = s;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[s][i] != 0)
        {
            d[i] = a[s][i];
        }
        else
        {
            d[i] = 99999;
        }
    }
    d[s] = 0;
}

int main()
{
    init();
    solve();
    for (int i = 1; i <= n; ++i)
    {
        cout << "K/c " << s << " -> " << i << " = ";
        if (d[i] == 99999 && i != s)
            cout << "INF;\n";
        else
        {
            cout << d[i] << ";        " << i << " <- ";
            int x = truoc[i];
            while (x != s)
            {
                cout << x << " <- ";
                x = truoc[x];
            }
            cout << s << endl;
        }
    }
}
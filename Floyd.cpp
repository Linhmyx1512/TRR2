#include <iostream>
using namespace std;

int n, a[100][100], d[100][100];
int nextt[100][100];

void solve()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    nextt[i][j] = nextt[i][k];
                }
            }
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

            if (a[i][j] != 0)
            {
                nextt[i][j] = j;
                d[i][j] = a[i][j];
            }
            else
            {
                nextt[i][j] = -1;
                d[i][j] = 99999;
            }
            if (i == j)
            {
                d[i][j] = 0;
                nextt[i][j] = i;
            }
        }
    }
}

void display()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << "K/c " << k << " --> " << i << " = ";

            if (d[k][i] == 99999)
            {
                cout << "INF";
                continue;
            }
            else
                cout << d[k][i];
            cout << ";   ";
            cout << k;
            int x = nextt[k][i];
            while (x != i)
            {
                cout << " -->   " << x;
                x = nextt[x][i];
            }
            if (i != k)
                cout << " -->   " << i;
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    init();
    solve();
    display();
}
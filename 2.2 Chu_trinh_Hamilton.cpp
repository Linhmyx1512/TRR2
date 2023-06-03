#include <iostream>
using namespace std;

int n, v0;
int a[100][100], ans[100], visited[100];

void Hmt(int k)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[ans[k - 1]][i] == 1)
        {
            if (k == n + 1 && i == v0)
            {
                for (int j = 1; j <= n; ++j)
                    cout << ans[j] << " ";
                cout << v0 << "\n";
            }
            else if (visited[i] == false)
            {
                ans[k] = i;
                visited[i] = true;
                Hmt(k + 1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    cin >> n >> v0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    ans[1] = v0;
    visited[v0] = true;
    Hmt(2);
}
#include <iostream>
#include <stack>

using namespace std;

int n, k;
int a[100][100];

void Euler(int u)
{
    stack<int> st, ce;

    st.push(u);
    while (st.size())
    {
        int s = st.top();
        int check = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][s] == 1)
            {
                check = 1;
                a[s][i] = a[i][s] = 0;
                st.push(i);
                break;
            }
        }
        if (!check)
        {
            st.pop();
            ce.push(s);
        }
    }

    while (ce.size())
    {
        cout << ce.top() << " ";
        ce.pop();
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    Euler(k);
}
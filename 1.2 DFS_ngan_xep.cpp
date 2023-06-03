#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 5][n + 5];
    int visited[n + 5] = {};
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    stack<int> st;
    st.push(1);
    cout << "1 ";
    visited[1] = 1;
    while (st.empty() != true)
    {
        int s = st.top();
        st.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (a[s][i] == 1 && visited[i] == 0)
            {
                cout << i << " ";
                visited[i] = 1;
                st.push(s);
                st.push(i);
                break;
            }
        }
    }
    return 0;
}
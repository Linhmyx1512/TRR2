#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int fi, se, w;
};

vector<Edge> g;
vector<int> v, vH;
int n, st, a[100][100], dH = 0;
vector<pair<int, int>> ans;

bool cmp(Edge a, Edge b)
{
    if (a.w == b.w)
    {
        if (a.fi == b.fi)
        {
            return a.se < b.se;
        }
        return a.fi < b.fi;
    }
    return a.w < b.w;
}

void init()
{
    cin >> n >> st;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (i < j && a[i][j])
            {
                g.push_back({i, j, a[i][j]});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (i == st)
            vH.push_back(i);
        else
            v.push_back(i);
    }
    sort(g.begin(), g.end(), cmp);
}

void Prim()
{
    while (v.size())
    {
        for (auto i : g)
        {
            if (find(vH.begin(), vH.end(), i.fi) != vH.end() && find(v.begin(), v.end(), i.se) != v.end())
            {
                vH.push_back(i.se);
                v.erase(find(v.begin(), v.end(), i.se));
                dH += i.w;
                ans.push_back({i.fi, i.se});
                break;
            }
            if (find(vH.begin(), vH.end(), i.se) != vH.end() && find(v.begin(), v.end(), i.fi) != v.end())
            {
                vH.push_back(i.fi);
                v.erase(find(v.begin(), v.end(), i.fi));
                dH += i.w;
                ans.push_back({i.fi, i.se});
                break;
            }
        }
    }
}

int main()
{
    init();
    Prim();
    cout << dH << endl;
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
}
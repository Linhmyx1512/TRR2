#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct canh
{
    int u, v, w;
};

bool cmp(canh a, canh b)
{
    if (a.w != b.w)
        return a.w < b.w;
    if (a.u != b.u)
        return a.u < b.u;
    return a.v < b.v;
}

int n, dH = 0;
int a[105][105];
vector<canh> edges;
int parent[105];

int find(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (v == u)
        return;
    parent[v] = u;
}

void kruskal()
{
    vector<pair<int, int>> ans;
    for (auto i : edges)
    {
        if (ans.size() == n - 1)
            break;
        if (find(i.u) != find(i.v))
        {
            join(i.u, i.v);
            dH += i.w;
            ans.push_back({i.u, i.v});
        }
    }
    cout << "dH = " << dH << endl;
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }
}

void init()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] && i < j)
            {
                edges.push_back({i, j, a[i][j]});
            }
        }
    }
    sort(edges.begin(), edges.end(), cmp);
}

int main()
{
    init();
    kruskal();
}

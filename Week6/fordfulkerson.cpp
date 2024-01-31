#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

int n, m, u, v, w, s, t, max_flow;
int edge[1009][1009], trace[1009], current_flow[1009][1009];
vector < int > adjacency[109];

int bfs_search()
{
    memset(trace, 0, sizeof(trace));
    queue < int > qu;
    trace[s] = -1;
    qu.push(s);
    while(qu.size())
    {
        u = qu.front(); qu.pop();
        if(u == t)
            return 1;
        for(auto v : adjacency[u])
            if(trace[v] == 0 && edge[u][v] > current_flow[u][v])
            {
                trace[v] = u;
                qu.push(v);
            }
    }
    return 0;
}

void ford_fulkerson()
{
    ll delta = 10000000000009, v;
    int u = t;

    while (u != s)
    {
        int v = trace[u];
        if(delta > edge[v][u] - current_flow[v][u])
            delta = edge[v][u] - current_flow[v][u];
        u = v;
    }
    u = t; max_flow+= delta;
    while (u != s)
    {
        int v = trace[u];
        current_flow[u][v] -= delta;
        current_flow[v][u] += delta;
        u = v;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s >> t;
    for(int i=1; i<=m; ++i)
    {
        cin >> u >> v >> w;
        adjacency[u].push_back(v);
        edge[u][v] = w;
    }

    while(bfs_search())
        ford_fulkerson();

 /*   for(auto v:adjacency[s])
        max_flow+= current_flow[s][v];*/

    cout << max_flow;
    return 0;
}
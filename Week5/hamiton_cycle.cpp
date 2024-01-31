#include <iostream>
#include <vector>

using namespace std;
const int MAXIMUM = 100000;

int  n, m;
vector<int> adj[MAXIMUM];
bool visited[100000];
int count_node, res;

void input()
{
    int u, v;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool is_cand(int u, int v)
{
    if (visited[v] == true)
        return false;
    return true;
}

void TRY(int curr)
{
    for (int next : adj[curr])
    {
        if (is_cand(curr, next))
        {
            visited[next] = true;
            count_node += 1;
            if (count_node == n)
                res = 1;
            else
                TRY(next);

            visited[next] = false;
            count_node -= 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        input();
        TRY(1);
        cout << res << endl;
    }
    return 0;
}
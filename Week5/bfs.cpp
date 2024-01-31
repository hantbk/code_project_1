#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int m,n;
vector<int> adj[100000];
bool visited[100000];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        sort(adj[u].begin(),adj[u].end());
        adj[v].push_back(u);
        sort(adj[v].begin(),adj[v].end());
    }
    memset(visited,false,sizeof(visited));
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    input();
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]) bfs(i);
    }
    return 0;
}
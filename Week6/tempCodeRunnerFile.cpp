#include<iostream>
#include<vector>
#include<queue>
#define MAXN 100001
#define ll long long
using namespace std;

int n,m,s,t;
vector<pair<int,int>> adj[MAXN];

void input(){
    cin>>n>>m;
    cin>>s>>t;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
}

bool bfs(int s, int t, int parent[]){
    bool visited[n+1];
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(!visited[v] && w>0){
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return visited[t];
}

void ford_fulkerson(int s, int t){
    int max_flow = 0;
    int parent[n+1];
    while (bfs(s,t,parent))
    {
        int path_flow = INT_MAX;
        for(int v=t;v!=s;v=parent[v]){
            int u = parent[v];
            for(auto it : adj[u]){
                if(it.first==v){
                    path_flow = min(path_flow,it.second);
                }
            }
        }
        for(int v=t;v!=s;v=parent[v]){
            int u = parent[v];
            for(auto &it : adj[u]){
                if(it.first==v){
                    it.second -= path_flow;
                }
            }
            for(auto &it : adj[v]){
                if(it.first==u){
                    it.second += path_flow;
                }
            }
        }
        max_flow += path_flow;
    }
    cout<<max_flow<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    ford_fulkerson(s,t);
    return 0;
}


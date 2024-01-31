#include<iostream>
#include<vector>
#include<queue>
#define MAXN 100001
#define ll long long
#define INF 1e18
using namespace std;

int n,m;
vector<pair<int,int>> adj[MAXN];
int pre[MAXN];

void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
}

void dijktra(int s, int t){
    vector<ll> dist(n+1,INF);
    vector<bool> visited(n+1,false);
    dist[s]=0;
    pre[s]=s;
    priority_queue<pair<int,int>, vector<pair<int, int>> , greater<pair<int,int>>> pq;
    pq.push({0,s});
    while (!pq.empty())
    {
        pair<int,int> top = pq.top();
        pq.pop();
        int u = top.second;
        int kc = top.first;
        if(visited[u]) continue;
        visited[u]=true;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
                pre[v]=u;
            }
        }
    }
    cout<<dist[t]<<" ";
//     vector<int> path;
//     while (1)
//     {
//         path.push_back(t);
//         if(t==s) break;
//         t=pre[t];
//     }
//    reverse(path.begin(),path.end());
//     for(int x : path){
//          cout<<x<<" ";
//     } 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();

    for (int i = 1; i <= n ; i++)
    {
        int j = 1;
        while (j <= n)
        {
            if(i==j) cout<<0<<" ";
            else dijktra(i,j);
            j++;
        }
        cout<<endl;
    }
    
    return 0;
}
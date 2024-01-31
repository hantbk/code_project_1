#include<iostream>
#include<vector>
const int MAX = 100000;
using namespace std;

struct edge{
    int u,v;
    int w;
};

int m,n;
int parent[MAX],sz[MAX];
vector<edge> edges;

void makeSet(){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edge e = edge{u,v,w};
        edges.push_back(e);
    } 
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    vector<edge> mst;
    int d = 0;
    sort(edges.begin(),edges.end(),cmp);
    for (int i = 0; i < m; i++)
    {
        if(mst.size() == n-1) break;
        edge e = edges[i];
        if(Union(e.u,e.v)){
            mst.push_back(e);
            d += e.w;
        }
    }
    cout << d;
}

int main(){
    input();
    makeSet();
    kruskal();
    return 0;
}
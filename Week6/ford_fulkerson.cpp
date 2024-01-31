// #include<iostream>
// #include<vector>
// #include<queue>
// #define MAXN 100001
// #define ll long long
// using namespace std;

// int n,m,s,t;
// vector<pair<int,int>> adj[MAXN];

// void input(){
//     cin>>n>>m;
//     cin>>s>>t;
//     for(int i=0;i<m;i++){
//         int u,v,w;
//         cin>>u>>v>>w;
//         adj[u].push_back({v,w});
//     }
// }

// bool bfs(int s, int t, int parent[]){
//     bool visited[n+1];
//     memset(visited,0,sizeof(visited));
//     queue<int> q;
//     q.push(s);
//     visited[s]=true;
//     parent[s]=-1;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for(auto it : adj[u]){
//             int v = it.first;
//             int w = it.second;
//             if(!visited[v] && w>0){
//                 q.push(v);
//                 parent[v]=u;
//                 visited[v]=true;
//             }
//         }
//     }
//     return visited[t];
// }

// void ford_fulkerson(int s, int t){
//     int max_flow = 0;
//     int parent[n+1];
//     while (bfs(s,t,parent))
//     {
//         int path_flow = INT_MAX;
//         for(int v=t;v!=s;v=parent[v]){
//             int u = parent[v];
//             for(auto it : adj[u]){
//                 if(it.first==v){
//                     path_flow = min(path_flow,it.second);
//                 }
//             }
//         }
//         for(int v=t;v!=s;v=parent[v]){
//             int u = parent[v];
//             for(auto &it : adj[u]){
//                 if(it.first==v){
//                     it.second -= path_flow;
//                 }
//             }
//             for(auto &it : adj[v]){
//                 if(it.first==u){
//                     it.second += path_flow;
//                 }
//             }
//         }
//         max_flow += path_flow;
//     }
//     cout<<max_flow<<endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     input();
//     ford_fulkerson(s,t);
//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int v;         // Đỉnh đích
    int capacity;  // Khả năng chứa (cạnh có thể chứa bao nhiêu đơn vị luồng)
    int flow;      // Luồng hiện tại trên cạnh

    Edge(int v, int capacity)
        : v(v), capacity(capacity), flow(0) {}
};

class Graph {
    int V;                  // Số đỉnh
    vector<vector<Edge>> adj; // Danh sách kề

    bool bfs(int s, int t, vector<int>& parent);
    int dfs(int s, int t, int minEdge, vector<int>& parent);

public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v, int capacity);
    int fordFulkerson(int s, int t);
};

void Graph::addEdge(int u, int v, int capacity) {
    Edge edge1(v, capacity);
    // Edge edge2(u, 0);  // Đối với đồ thị vô hướng, đặt capacity = 0
    adj[u].push_back(edge1);
    // adj[v].push_back(edge2);
}

bool Graph::bfs(int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const Edge& edge : adj[u]) {
            int v = edge.v;
            int capacity = edge.capacity;
            int flow = edge.flow;

            if (!visited[v] && capacity > flow) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int Graph::dfs(int s, int t, int minEdge, vector<int>& parent) {
    if (s == t)
        return minEdge;

    for (Edge& edge : adj[s]) {
        int v = edge.v;
        int capacity = edge.capacity;
        int flow = edge.flow;

        if (parent[v] == s && capacity > flow) {
            int minFlow = dfs(v, t, min(minEdge, capacity - flow), parent);

            if (minFlow > 0) {
                edge.flow += minFlow;

                // Cập nhật luồng ngược
                for (Edge& reverseEdge : adj[v]) {
                    if (reverseEdge.v == s) {
                        reverseEdge.flow -= minFlow;
                        break;
                    }
                }

                return minFlow;
            }
        }
    }

    return 0;
}

int Graph::fordFulkerson(int s, int t) {
    vector<int> parent(V);
    int maxFlow = 0;
    int minEdge;

    while (bfs(s, t, parent)) {
        while ((minEdge = dfs(s, t, numeric_limits<int>::max(), parent)) > 0) {
            maxFlow += minEdge;
        }
    }

    return maxFlow;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph.addEdge(u, v, capacity);
    }

    int maxFlow = graph.fordFulkerson(s, t);
    cout << "Max Flow: " << maxFlow << endl;

    return 0;
}

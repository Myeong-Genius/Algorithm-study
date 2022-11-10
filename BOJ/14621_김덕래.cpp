#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;

struct Edge{
    int n1, n2;
    int dist;
    Edge(int n1_, int n2_, double dist_) : n1(n1_), n2(n2_), dist(dist_) { }
    bool operator<(const Edge& e2) const{
        return dist < e2.dist;
    }
};
priority_queue<Edge> edges;
int parent[1001], n, m, graph_size;
double answer;

void input();
void solve();
void union_edges();
int getroot(int n);

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> n >> m;
    char sex[1001] = {0, };
    for(int i = 1; i <= n; i++){
        cin >> sex[i];
    }

    for(int i = 0; i < m; i++){
        int n1, n2, dist;
        cin >> n1 >> n2 >> dist;
        if(sex[n1] != sex[n2])
            edges.push(Edge(n1, n2, -dist));
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    union_edges();

    if(graph_size == n - 1)
        cout << answer;
    else
        cout << -1;
}

void union_edges(){
    for(int i = 0; i < n - 1 && !edges.empty();){
        // cout << i;
        Edge e = edges.top();
        int p1 = getroot(e.n1), p2 = getroot(e.n2);
        if(p1 != p2){
            parent[p2] = parent[p1] = parent[e.n1] = parent[e.n2] = min(p1, p2);
            answer -= e. dist;
            i++;
            graph_size++;
        }
        edges.pop();
    }
}

int getroot(int n){
    while(parent[n] != n)
        n = parent[n];
    return n;
}
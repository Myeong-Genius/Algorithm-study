#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include <queue>
using namespace std;

struct Edge{
    int n1, n2;
    double dist;
    Edge(int n1_, int n2_, double dist_) : n1(n1_), n2(n2_), dist(dist_) { }
    friend bool operator<(const Edge& e1, const Edge& e2){
        return e1.dist < e2.dist;
    }
};
priority_queue<Edge> edges;
int parent[100001], n, m, answer;

void input();
void solve();
void push_edges();
void union_edges();
int getroot(int n);

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int n1, n2, d;
        cin >> n1 >> n2 >> d;
        if(n1 > n2){
            int tmp = n1, n1 = n2, n2 = tmp;
        }
        edges.push(Edge(n1, n2, -d));
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    union_edges();
    cout << fixed;
    cout.precision(2);
    cout << answer;
}

void union_edges(){
    for(int i = 0; i < n - 1;){
        Edge e = edges.top();
        int p1 = getroot(e.n1), p2 = getroot(e.n2);
        if(p1 != p2){
            parent[p2] = parent[p1]= parent[e.n1] = parent[e.n2] = min(p1, p2);
            if(i != n-2)
                answer -= e.dist;
            i++;
        }
        edges.pop();
    }
}

int getroot(int n){
    while(parent[n] != n)
        n = parent[n];
    return n;
}
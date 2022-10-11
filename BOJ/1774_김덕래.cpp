#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include <queue>
using namespace std;

struct Coordinate{
    long long x, y;
    Coordinate(long long x_, long long y_) : x(x_), y(y_) {}
};
struct Edge{
    int n1, n2;
    double dist;
    Edge(int n1_, int n2_, double dist_) : n1(n1_), n2(n2_), dist(dist_) { }
    friend bool operator<(const Edge& e1, const Edge& e2){
        return e1.dist < e2.dist;
    }
};
vector<Coordinate> nodes;
priority_queue<Edge> edges;
int parent[1001], n, m;
double answer;

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
    for(int i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;
        nodes.push_back(Coordinate(x, y));
    }

    for(int i = 0; i < m; i++){
        int n1, n2;
        cin >> n1 >> n2;
        if(n1 > n2){
            int tmp = n1, n1 = n2, n2 = tmp;
        }
        edges.push(Edge(n1, n2, 0.));
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    push_edges();
    union_edges();
    cout << fixed;
    cout.precision(2);
    cout << answer;
}

void push_edges(){
    for(int i = 0; i < nodes.size() - 1; i++){
        for(int j = i + 1; j < nodes.size(); j++){
            double dist = sqrt(pow((nodes[i].x - nodes[j].x), 2) + pow((nodes[i].y - nodes[j].y), 2));
            edges.push(Edge(i + 1, j + 1, -dist));
        }
    }
}

void union_edges(){
    for(int i = 0; i < n - 1;){
        Edge e = edges.top();
        int p1 = getroot(e.n1), p2 = getroot(e.n2);
        if(p1 != p2){
            parent[p2] = parent[p1]= parent[e.n1] = parent[e.n2] = min(p1, p2);
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
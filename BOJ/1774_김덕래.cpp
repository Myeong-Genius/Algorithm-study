#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;
struct Edge{
    int n1, n2;
    double l;
    Edge(int _n1, int _n2, double _l) : n1(_n1), n2(_n2), l(_l) { }
    bool operator<(Edge &e){
        return l < e.l;
    }
};
struct Coordinate{
    long long x,y;
};
Coordinate god_coord[1001];
vector<Edge> edge;
int parent[1001], n_node, n_edge;
double answer;

void input();
void solve();
void compute_edges();
bool compare_edge(Edge i, Edge j);
void kruskal();

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> n_node >> n_edge;
    for(int i = 1; i <= n_node; i++){
        cin >> god_coord[i].x >> god_coord[i].y;
    }
    for(int i = 0; i < n_edge; i++){
        int n1, n2;
        cin >> n1 >> n2;
        if(n1 < n2)
            edge.push_back(Edge(n1, n2, 0.));
        else
            edge.push_back(Edge(n2, n1, 0.));
        // answer += sqrt(pow((god_coord[n1].x - god_coord[n2].x), 2) + pow((god_coord[n1].y - god_coord[n2].y), 2));
    }
}

void solve(){
    for(int i = 1; i <= n_node; i++)
        parent[i] = i;
    compute_edges();
    sort(edge.begin(), edge.end(), compare_edge);
    kruskal();
    cout << fixed;
    cout.precision(2);
    cout << round(answer * 100.) / 100.;
}

void compute_edges(){
    for(int i = 2; i <= n_node; i++){
        for(int j = 1; j < i; j++){
            long long dx = (god_coord[i].x - god_coord[j].x) * (god_coord[i].x - god_coord[j].x);
            long long dy = (god_coord[i].y - god_coord[j].y) * (god_coord[i].y - god_coord[j].y);
            edge.push_back(Edge(j, i, sqrt(dx + dy)));
        }
    }
}

bool compare_edge(Edge i, Edge j){
    return i.l < j.l;
}

void kruskal(){
    n_edge = 0;
    int j = 0;
    while(n_edge != n_node - 1){
        Edge e = edge[j++];
        if(parent[e.n1] != parent[e.n2]){
            parent[e.n2] = parent[e.n1];
            answer += e.l;
            n_edge++;
        }
    }
}
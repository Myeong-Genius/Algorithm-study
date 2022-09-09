#include<iostream>
#include<vector>
#include<algorithm>
#define INF 100000
using namespace std;

struct Edge{
    int dest, len;
};
vector<Edge> graph[101];
vector<int> visited;
int dist[101], items[101];
int answer, n, m, r;

void input();
int findClosestNode();
void dijkstra(int node);
void solve();

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> items[i];
    }
    for(int i = 0; i < r; i++){
        int n1, n2, l;
        cin >> n1 >> n2 >> l;
        graph[n1].push_back({n2, l});
        graph[n2].push_back({n1, l});
    }
}

int findClosestNode(){
    int node = 0, l = INF;
    for(auto it = visited.begin(); it != visited.end(); ++it){
        for(auto it2 = graph[*it].begin(); it2 != graph[*it].end(); ++it2){
            if(find(visited.begin(), visited.end(), it2 -> dest) == visited.end() && dist[it2 -> dest] < l){
                node = it2 -> dest;
                l = dist[it2 -> dest]
            }
        }
    }
    return node;
}

void dijkstra(int node){
    visited.push_back(node);
    for(auto it = graph[node].begin(); it != graph[node].end(); ++it){
        dist[it -> dest] = min(dist[it -> dest], dist[node] + it -> len);
    }
    int next = findClosestNode();
    if(next){
        dijkstra(next);
    }
}



void solve(){
    for(int i = 1; i <= n; i++){
        int item = 0;
        fill(dist, dist + 101, INF);
        visited.clear();
        dist[i] = 0;
        dijkstra(i);
        for(int i = 1; i <= n; i++){
            if(dist[i] <= m){
                item += items[i];
            }
        }
        answer = max(answer, item);
    }
    cout << answer;
}
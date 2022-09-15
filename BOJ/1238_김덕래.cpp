#include<iostream>
#include<vector>
#define INF 1000000
using namespace std;

int n, m, x, graph[1001][1001];
void input();
void floyd_warshall();
void solve();

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++){
        fill(graph[i], graph[i] + n + 1, INF);
        graph[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src][dest] = weight;
    }
}

void floyd_warshall(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
}

void solve(){
    int answer = 0;
    floyd_warshall();
    for(int i = 1; i <= n; i++){
        answer = max(graph[x][i] + graph[i][x], answer);
    }
    cout << answer;
}
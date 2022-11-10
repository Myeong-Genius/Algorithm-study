#include<iostream>
#define INF 10000001
using namespace std;

int n_city, n_bus;
int dist[101][101];

void input(){
    cin >> n_city >> n_bus;
    fill(&dist[1][1], &dist[n_city][n_city + 1], INF);
    for(int i = 0; i < n_bus; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        dist[from][to] = min(cost, dist[from][to]);
    }
}

void solve(){
    for(int i = 1; i <= n_city; i++)  dist[i][i] = 0;
    for(int k = 1; k <= n_city; k++){
        for(int i = 1; i <= n_city; i++){
            for(int j = 1; j <= n_city; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 1; i <= n_city; i++){
        for(int j = 1; j <= n_city; j++){
            if(dist[i][j] == INF) cout << "0 ";
            else  cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    input();
    // for(int i = 1; i <= n_city; i++){
    //     for(int j = 1; j <= n_city; j++){
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    solve();
    return 0;
}
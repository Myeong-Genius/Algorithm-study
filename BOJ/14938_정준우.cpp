#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, m, r, a, b, l, ans;
int map[100][100], dist[100], item_cnt[100];
void solved_by_floyd_warshall(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        int cnt = 0;

        for(int j = 0; j < n; j++){
            if(map[i][j] > m) continue;
            cnt += item_cnt[j];
        }
        ans = max(ans, cnt);
    }
}
void solved_by_dijkstra(){
    priority_queue<pair<int, int> > heap;

    for(int i = 0; i < n; i++){
        int cnt = 0;

        for(int j = 0; j < n; j++) dist[j] = 1500;
        dist[i] = 0;
        heap.push({0, i});
        while(!heap.empty()){
            int node, dis;

            node = heap.top().second;
            dis = -heap.top().first;
            heap.pop();

            for(int j = 0; j < n; j++){
                if(dist[j] > dis + map[node][j]){
                    dist[j] = dis + map[node][j];
                    heap.push({-dist[j], j});
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(dist[j] > m) continue;
            cnt += item_cnt[j];
        }
        ans = max(ans, cnt);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;
    for(int i = 0; i < n; i++) cin >> item_cnt[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) if(i != j) map[i][j] = 1500;
    }
    for(int i = 0; i < r; i++){
        cin >> a >> b >> l;
        map[a - 1][b - 1] = map[b - 1][a - 1] = l;
    }
    solved_by_dijkstra();
    cout << ans;
    return 0;
}
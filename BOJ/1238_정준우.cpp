#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, X, dist[1001], to_X_dist[1001], max_dist;
vector<pair<int, int> > graph[1001], reverse_graph[1001];
void dijkstra(int start, const vector<pair<int, int> > (&target_graph)[1001]){
    priority_queue<pair<int, int> > heap;

    for(int i = 0; i < 1001; i++) dist[i] = 100001;
    dist[start] = 0;
    heap.push({0, start});
    while(!heap.empty()){
        int cur = heap.top().second;
        int cur_dist = -heap.top().first;

        heap.pop();
        for(int i = 0; i < target_graph[cur].size(); i++){
            int next = target_graph[cur][i].first;
            int next_dist = target_graph[cur][i].second;

            if(dist[next] > cur_dist + next_dist){
                dist[next] = cur_dist + next_dist;
                heap.push({-dist[next], next});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> X;
    while(M--){
        int start, end, dist;

        cin >> start >> end >> dist;
        graph[start].push_back({end, dist});
        reverse_graph[end].push_back({start, dist});
    }
    dijkstra(X, reverse_graph);
    for(int i = 1; i <= N; i++) to_X_dist[i] += dist[i];
    dijkstra(X, graph);
    for(int i = 1; i <= N; i++){
        to_X_dist[i] += dist[i];
        max_dist = max(max_dist, to_X_dist[i]);
    }
    cout << max_dist;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 99999999

using namespace std;

int N, M, X, ans;
int dis[1001], sum[1001];
vector<pair<int, int> > graph[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    dis[start] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextCost = cost + graph[cur][i].second;

            if(nextCost < dis[next]) {
                dis[next] = nextCost;
                pq.push(make_pair(-nextCost, next));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    for(int i = 0; i < M; i++) {
        int start, end, value;
        cin >> start >> end >> value;
        graph[start].push_back(make_pair(end, value));
    }

    for(int i = 1; i <= N; i++) {
        fill(dis, dis + N + 1, INF);
        dijkstra(i);
        sum[i] = dis[X];
    }

    fill(dis, dis + N + 1, INF);
    dijkstra(X);

    for(int i = 1; i <= N; i++) {
        sum[i] += dis[i];
        if(sum[i] > ans) {
            ans = sum[i];
        }
    }
    cout << ans << "\n";

    return 0;
}
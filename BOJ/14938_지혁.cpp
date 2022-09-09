#include <iostream>
#include <vector>
#include <queue>

#define INF 99999999

using namespace std;

int n, m, r;
int item[101];
vector<pair<int, int> > graph[101];
int dist[101];
int ans = 0;

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextCost = cost + graph[cur][i].second;

            if(nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push(make_pair(-nextCost, next));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    for(int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;

        graph[a].push_back(make_pair(b, l));
        graph[b].push_back(make_pair(a, l));
    }

    for(int i = 1; i <= n; i++) {
        int tmp = 0;
        for(int j = 1; j <= n; j++) {
            dist[j] = INF;
        }
        dijkstra(i);

        for(int j = 1; j <= n; j++) {
            if(dist[j] <= m) {
                tmp += item[j];
            }
        }

        if(ans < tmp) {
            ans = tmp;
        }
    }

    cout << "\n" << ans << "\n";

    return 0;
}
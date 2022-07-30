#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int> > tree[1001];
int dis[1001];
bool visited[1001];

int bfs(int start, int target) {
    fill(dis, dis + 1001, 0);
    fill(visited, visited + 1001, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < tree[x].size(); i++) {
            if(!visited[tree[x][i].first]) {
                dis[tree[x][i].first] = dis[x] + tree[x][i].second;
                visited[tree[x][i].first] = true;
                q.push(tree[x][i].first);
            }
        }
    }

    return dis[target];
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N - 1; i++) {
        int x, y, d;
        cin >> x >> y >> d;

        tree[x].push_back(make_pair(y, d));
        tree[y].push_back(make_pair(x, d));
    }

    for(int i = 0; i < M; i ++) {
        int a, b;
        cin >> a >> b;

        cout << bfs(a, b) << endl;
    }

    return 0;
}
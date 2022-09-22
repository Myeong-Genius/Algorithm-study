#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> in_degree, ans;
vector<int> graph[1001];

void topology_sort() {
    queue<pair<int, int> > q;

    for(int i = 1; i <= N; i++) {
        if(in_degree[i] == 0) {
            q.push(make_pair(i, 1));
            ans[i] = 1;
        }
    }

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int j = 0; j < graph[cur.first].size(); j++) {
            int next = graph[cur.first][j];
            if(--in_degree[next] == 0) {
                q.push(make_pair(next, cur.second + 1));
                ans[next] = cur.second + 1;
            }
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        in_degree.push_back(0);
        ans.push_back(0);
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        in_degree[b]++;
        graph[a].push_back(b);
    }
    topology_sort();

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
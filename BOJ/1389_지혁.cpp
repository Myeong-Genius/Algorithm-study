#include <iostream>
#include <queue>

using namespace std;

int friends[101][101];
int n, m;
int visited[101];
queue<int> q;

void bfs(int v) {
    q.push(v);
    visited[v]++;

    while(!q.empty()) {
        int r = q.size();
        while(r--) {
            int x = q.front();
            q.pop();
            for(int i = 1; i <= n; i++) {
                if(friends[x][i] != 1 || visited[i] >= 0) {
                    continue;
                }
                q.push(i);
                visited[i] = visited[x] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        friends[a][b] = 1;
        friends[b][a] = 1;
    }
    
    int min = 100000000, ans;
    for(int i = 1; i <= n; i++) {
        for(int i = 1; i <= n; i++) {
            visited[i] = -1;
        }
        bfs(i);
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += visited[i];
        }
        if(sum < min) {
            min = sum;
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
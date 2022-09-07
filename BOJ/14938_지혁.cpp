#include <iostream>

using namespace std;

int n, m, r;
int item[101];
int graph[101][101];
bool visited[101];
int curCount, maxCount;

void dfs(int index, int depth) {
    if(visited[index]) {
        return;
    }
    if(depth > m) {
        return;
    }
    visited[index] = true;
    curCount += item[index];
    for(int i = 1; i <= n; i++) {
        if(graph[index][i] != 0 && !visited[i]) {
            dfs(i, depth + graph[index][i]);
        }
    }
    return;
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
        int x, y, v;
        cin >> x >> y >> v;
        graph[x][y] = v;
        graph[y][x] = v;
    }

    for(int i = 1; i <= n; i++) {
        curCount = 0;
        for(int j = 1; j <= n; j++) {
            visited[j] = false;
        }
        dfs(i, 0);
        if(curCount > maxCount) {
            maxCount = curCount;
        }
    }

    cout << maxCount << "\n";
    
    return 0;
}
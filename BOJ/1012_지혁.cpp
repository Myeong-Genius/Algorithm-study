#include <iostream>

using namespace std;

int bat[51][51];
bool visited[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(bat[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < 51; j++) {
            for(int k = 0; k < 51; k++) {
                bat[j][k] = 0;
                visited[j][k] = false;
            }
        }

        int m, n, k, result = 0;
        cin >> m >> n >> k;

        for(int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;

            bat[x][y] = 1;
        }

        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(bat[x][y] == 1 && !visited[x][y]) {
                    result++;
                    dfs(x, y);
                }
            }
        }

        cout << result << endl;
    }
}
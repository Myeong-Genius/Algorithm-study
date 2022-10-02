#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Position {
    int x, y;
};
int paper[101][101];
int outAir[101][101];
int N, M, passedHours;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[101][101];

void checkAir() {
    queue<Position> q;
    Position first = {0, 0};
    q.push(first);

    while(!q.empty()) {
        Position current = q.front();
        int x = current.x;
        int y = current.y;
        q.pop();
        if(visited[x][y]) {
            continue;
        }
        visited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
                continue;
            }
            if(paper[nx][ny] == 1) {
                outAir[nx][ny]++;
            }
            else if(!visited[nx][ny]) {
                Position next = {nx, ny};
                q.push(next);
            }
        }
    }
}

void passed1Hour() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(outAir[i][j] >= 2) {
                paper[i][j] = 0;
            }
        }
    }
}

bool checkEmpty() {
    bool isEmpty = true;

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            if(paper[i][j] == 1) {
                isEmpty = false;
            }
        }
    }

    return isEmpty;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    // checkAir();
    // passed1Hour();
    // for(int i = 0; i <= N; i++) {
    //     for(int j = 0; j <= M; j++) {
    //         cout << outAir[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for(int i = 0; i <= N; i++) {
    //     for(int j = 0; j <= M; j++) {
    //         cout << paper[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    while(!checkEmpty()) {
        memset(visited, false, sizeof(visited));
        memset(outAir, 0, sizeof(outAir));
        checkAir();
        passed1Hour();
        passedHours++;
    }

    cout << passedHours << "\n";

    return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int box[1001][1001];
int visited[1001][1001];
int day = -1;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue< pair<int,int> > q;

int main() {
    cin >> M >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> box[i][j];
            visited[i][j] = -1;

            if(box[i][j] == 1) {
                q.push(make_pair(i, j));
                visited[i][j]++;
            }
        }
    }

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if(na >= 0 && nb >= 0 && N > na && M > nb && visited[na][nb] == -1 && box[na][nb] == 0) {
                q.push(make_pair(na, nb));
                box[na][nb] = 1;
                visited[na][nb] = visited[a][b] + 1;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(day <= visited[i][j]) {
                day = visited[i][j];
            }
            if(box[i][j] == 0) {
                day = -1;
                cout << -1;
                return 0;
            }
        }
    }

    cout << day << endl;
    return 0;
}
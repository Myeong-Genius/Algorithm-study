#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int dis[100001];
bool visited[100001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if((2 * x) <= 100000) {
            int y = 2 * x;
            if(!visited[y]) {
                q.push(y);
                dis[y] = dis[x] + 1;
                visited[y] = true;
            }
        }
        if((x + 1) <= 100000) {
            int y = x + 1;
            if(!visited[y]) {
                q.push(y);
                dis[y] = dis[x] + 1;
                visited[y] = true;
            }
        }
        if((x - 1) >= 0) {
            int y = x - 1;
            if(!visited[y]) {
                q.push(y);
                dis[y] = dis[x] + 1;
                visited[y] = true;
            }
        }
    }
}

int main() {
    cin >> N >> K;

    bfs(N);

    cout << dis[K] << endl;

    return 0;
}
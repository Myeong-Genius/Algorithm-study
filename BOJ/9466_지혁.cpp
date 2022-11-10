#include <iostream>
#include <cstring>

using namespace std;

int T, n;
int graph[100001];
bool visited[100001];
bool done[100001];
int cnt;

void has_cycle(int node) {
    visited[node] = true;
    int next = graph[node];

    if(!visited[next]) {
        has_cycle(next);
    }
    else if(!done[next]) {
        for(int i = next; i != node; i = graph[i]) {
            cnt++;
        }
        cnt++;
    }
    done[node] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> n;
        for(int j = 1; j <= n; j++) {
            cin >> graph[j];
        }
        for(int j = 1; j <= n; j++) {
            if(!visited[j]) {
                has_cycle(j);
            }
        }
        cout << n - cnt << "\n";
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
    }

    return 0;
}
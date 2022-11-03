#include <algorithm>
#include <iostream>

#define INF 999999999

using namespace std;

int n, m;
int floyd[101][101];

void floyd_warshall() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(floyd[j][i] != INF && floyd[i][k] != INF) {
                    floyd[j][k] = min(floyd[j][k], floyd[j][i] + floyd[i][k]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            floyd[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(floyd[a][b] > c) {
            floyd[a][b] = c;
        }
    }

    floyd_warshall();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || floyd[i][j] == INF) {
                cout << "0" << " ";
            }
            else {
                cout << floyd[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
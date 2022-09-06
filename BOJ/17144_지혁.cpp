#include <iostream>

using namespace std;

int R, C, T;
int A[51][51], add[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void diffuse() {
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(A[i][j] >= 5) {
                int count = 0;
                for(int k = 0; k < 4; k++) {
                    if((i + dx[k]) > 0 && (j + dy[k]) > 0 && (i + dx[k]) <= R && (j + dy[k]) <= C) {
                        if(A[i + dx[k]][j + dy[k]] != -1) {
                            add[i + dx[i]][j + dy[k]] += (A[i][j] / 5);
                            count++;
                        }
                    }
                }
                A[i][j] -= (A[i][j] / 5) * count;
            }
        }
    }

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            A[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> A[i][j];
        }
    }

    diffuse();

    for(int i = 0; i <= R; i++) {
        for(int j = 0; j <= C; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
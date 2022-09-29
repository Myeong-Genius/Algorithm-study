#include <iostream>

using namespace std;

int paper[101][101];
int N, M, passedHours;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void markC() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(paper[i][j] == 1) {
                int count = 0;
                for(int k = 0; k < 4; k++) {
                    if(paper[i + dx[k]][j + dy[k]] == 0) {
                        count++;
                    }
                }
                if(count >= 2) {
                    paper[i][j] = 67;
                }
            }
        }
    }
}

void passed1Hour() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(paper[i][j] == 67) {
                paper[i][j] = 0;
            }
        }
    }
}

bool checkEmpty() {
    bool isEmpty = true;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
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
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> paper[i][j];
        }
    }

    while(!checkEmpty()) {
        markC();
        passed1Hour();
        passedHours++;
    }

    cout << passedHours << "\n";

    return 0;
}
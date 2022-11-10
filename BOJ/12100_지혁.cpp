#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long ans;

long long calculate_max(vector<vector<long long> > board) {
    long long result = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            result = max(result, board[i][j]);
        }
    }
    return result;
}

vector<vector<long long> > right(vector<vector< long long> > board) {
    vector<vector<bool> > check(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++) {
        for(int j = N - 2; j >= 0; j--) {
            if(board[i][j] == 0) {
                continue;
            }
            for(int k = j + 1; k < N; k++) {
                if(board[i][k] == board[i][k - 1] && !check[i][k]) {
                    board[i][k] *= 2;
                    board[i][k - 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if(board[i][k] == 0) {
                    board[i][k] = board[i][k - 1];
                    board[i][k - 1] = 0;
                }
                else {
                    break;
                }
            }
        }
    }
    return board;
}

vector<vector<long long> > left(vector<vector< long long> > board) {
    vector<vector<bool> > check(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++) {
        for(int j = 1; j < N; j++) {
            if(board[i][j] == 0) {
                continue;
            }
            for(int k = j - 1; k >= 0; k--) {
                if(board[i][k] == board[i][k + 1] && !check[i][k]) {
                    board[i][k] *= 2;
                    board[i][k + 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if(board[i][k] == 0) {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                }
                else {
                    break;
                }
            }
        }
    }
    return board;
}

vector<vector<long long> > down(vector<vector< long long> > board) {
    vector<vector<bool> > check(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++) {
        for(int j = N - 2; j >= 0; j--) {
            if(board[i][j] == 0) {
                continue;
            }
            for(int k = j + 1; k < N; k++) {
                if(board[k][i] == board[k - 1][i] && !check[k][i]) {
                    board[k][i] *= 2;
                    board[k - 1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if(board[k][i] == 0) {
                    board[k][i] = board[k - 1][i];
                    board[k - 1][i] = 0;
                }
                else {
                    break;
                }
            }
        }
    }
    return board;
}

vector<vector<long long> > up(vector<vector< long long> > board) {
    vector<vector<bool> > check(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++) {
        for(int j = 1; j < N; j++) {
            if(board[i][j] == 0) {
                continue;
            }
            for(int k = j - 1; k >= 0; k--) {
                if(board[k][i] == board[k + 1][i] && !check[k][i]) {
                    board[k][i] *= 2;
                    board[k + 1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if(board[k][i] == 0) {
                    board[k][i] = board[k + 1][i];
                    board[k + 1][i] = 0;
                }
                else {
                    break;
                }
            }
        }
    }
    return board;
}

void dfs(int count, vector<vector<long long> > board) {
    ans = max(ans, calculate_max(board));
    if(count == 5) {
        return;
    }
    dfs(count + 1, right(board));
    dfs(count + 1, left(board));
    dfs(count + 1, down(board));
    dfs(count + 1, up(board));
}

int main() {
    cin >> N;

    vector<vector<long long> > board(N, vector<long long>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, board);
    cout << ans << '\n';

    return 0;
}
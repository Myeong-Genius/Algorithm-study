#include <iostream>

using namespace std;

int N;
int media[64][64];

void compress(int n, int x, int y) {
    if(n == 1) {
        cout << media[x][y];
        return;
    }

    int first_element = media[x][y];
    bool is_same = true;
    for(int i = x; i < x + n; i++) {
        for(int j = y; j < y + n; j++) {
            if(media[i][j] != first_element) {
                is_same = false;
                break;
            }
        }
    }

    if(is_same) {
        cout << first_element;
    }
    else {
        cout << "(";
        compress(n / 2, x, y);
        compress(n / 2, x, y + n / 2);
        compress(n / 2, x + n / 2, y);
        compress(n / 2, x + n / 2, y + n / 2);
        cout << ")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < N; j++) {
            media[i][j] = tmp[j] - '0';
        }
    }

    compress(N, 0, 0);
    cout << "\n";

    return 0;
}
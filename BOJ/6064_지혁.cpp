#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int M, N, x, y, j;
        cin >> M >> N >> x >> y;

        for(j = x; j <= lcm(M, N); j += M) {
            int tmp = (j % N == 0) ? N : j % N;
            if(tmp == y) {
                cout << j << endl;
                break;
            }
        }
        if(j > lcm(M, N)) {
            cout << -1 << endl;
        }
    }
    return 0;
}
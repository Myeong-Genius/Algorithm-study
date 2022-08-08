#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1500002], T[1500002], P[1500002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for(int i = 1; i <= N; i++) {
        if(i + T[i] <= N + 1) {
            if(dp[i + T[i]] < dp[i] + P[i]) {
                fill(dp + i + T[i], dp + N + 1, dp[i] + P[i]);
            }
        }
    }

    for(int i = 1; i <= N + 1; i++) {
        cout << dp[i] << endl;
    }

    return 0;
}
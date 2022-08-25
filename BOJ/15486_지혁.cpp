#include <iostream>
#include <algorithm>

using namespace std;

int N, currentMax;
int dp[1500002], T[1500002], P[1500002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for(int i = 1; i <= N + 1; i++) {
        currentMax = max(currentMax, dp[i]);
        dp[i] = currentMax;
        if(i + T[i] <= N + 1) {
            if(dp[i + T[i]] < dp[i] + P[i]) {
                dp[i + T[i]] = dp[i] + P[i];
            }
        }
    }

    cout << dp[N + 1] << endl;

    return 0;
}
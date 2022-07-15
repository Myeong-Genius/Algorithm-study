#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0;
    int dp[501];

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int count = 0;
        int tmp = i;

        while(tmp % 5 == 0) {
            count++;
            tmp /= 5;
        }
        dp[i] = count;
    }

    for(int i = 1; i <= n; i++) {
        result += dp[i];
    }
    cout << result << endl;

    return 0;
}
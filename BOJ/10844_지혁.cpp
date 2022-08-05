#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[101][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for(int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0) {
                dp[i][0] = dp[i - 1][j + 1] % 1000000000;
            }
            else if(j == 9) {
                dp[i][9] = dp[i - 1][j - 1] % 1000000000;
            }
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
        }
    }

    int result = 0;
    for(int i = 0; i <= 9; i++) {
        result = (result + dp[N][i]) % 1000000000;
    }
    cout << result << endl;

    return 0;
}
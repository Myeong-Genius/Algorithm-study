#include <iostream>

using namespace std;

int N, ans;
int arr[1001], dp[1001], rdp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++) {
        dp[i] = 1;
        for(int j = 1; j <= i; j++) {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for(int i = N; i >= 1; i--) {
        rdp[i] = 1;
        for(int j = N; j >= i; j--) {
            if(arr[i] > arr[j] && rdp[j] + 1 > rdp[i]) {
                rdp[i] = rdp[j] + 1;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(ans < dp[i] + rdp[i] - 1) {
            ans = dp[i] + rdp[i] - 1;
        }
    }
    cout << ans << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1010
using namespace std;

int N;
int dp[MAX];
int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[i + 1] = tmp;
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        dp[i] = 1;
        for(int j = i - 1; j >= 1; j--) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }

    cout << ans << endl;

    return 0;
}
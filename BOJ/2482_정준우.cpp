#include<iostream>
using namespace std;

const int MOD = 1000000003;
int N, K, DP[1001][1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        DP[i][0] = 1;
        DP[i][1] = i;
    }
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= K; j++){
            DP[i][j] = (DP[i - 1][j] + DP[i - 2][j - 1]) % MOD;
        }
    }
    DP[N][K] = (DP[N - 1][K] + DP[N - 3][K - 1]) % MOD;
    cout << DP[N][K];
    return 0;
}
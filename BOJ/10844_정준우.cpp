#include<iostream>
#include<algorithm>

#define MOD 1000000000
using namespace std;

int N, DP[101][11], ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    fill(&DP[1][1], &DP[1][1] + 9, 1);
    for(int i = 2; i < N + 1; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0) DP[i][j] = DP[i-1][j+1] % MOD;
            else{
                DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % MOD;
            }
        }
    }
    for(int i = 0; i < 10; i++) ans = (ans + DP[N][i]) % MOD;
    cout << ans;
}
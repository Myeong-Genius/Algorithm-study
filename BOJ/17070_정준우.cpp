#include<iostream>
using namespace std;

int N, MAP[16][16], DP[16][16][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    DP[0][1][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> MAP[i][j];
    }
    for(int i = 0; i < N; i++){
        for(int j = 2; j < N; j++){
            if(!MAP[i][j]){
                DP[i][j][0] = DP[i][j-1][0] + DP[i][j-1][2];
                if(i > 0) DP[i][j][1] = DP[i-1][j][1] + DP[i-1][j][2];
            }
            if(i > 0 && !MAP[i][j] && !MAP[i-1][j] && !MAP[i][j-1]){
                DP[i][j][2] = DP[i-1][j-1][0] + DP[i-1][j-1][1] + DP[i-1][j-1][2];
            }
        }
    }
    cout << DP[N-1][N-1][0] + DP[N-1][N-1][1] + DP[N-1][N-1][2];
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int N, ARR[1000][2], DP[1000][2], ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ARR[i][0];
        ARR[N - i - 1][1] = ARR[i][0];
    }
    for(int i = 0; i < N; i++){
        DP[i][0] = 1;
        DP[i][1] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(ARR[i][0] > ARR[j][0]){
                DP[i][0] = max(DP[i][0], DP[j][0] + 1);
            }
            if(ARR[i][1] > ARR[j][1]){
                DP[i][1] = max(DP[i][1], DP[j][1] + 1);
            }
        }
    }
    for(int i = 0; i< N; i++){
        ans = max(DP[i][0] + DP[N - i - 1][1] - 1, ans);
    }
    cout << ans;
    return 0;
}
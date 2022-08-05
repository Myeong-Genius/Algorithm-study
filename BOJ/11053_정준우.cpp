#include<iostream>
#include<algorithm>
using namespace std;

int N, ARR[1000], DP[1000], ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ARR[i];
    }
    for(int i = 0; i < N; i++){
        DP[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(ARR[i] > ARR[j]){
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        ans = max(DP[i], ans);
    }
    cout << ans;
}
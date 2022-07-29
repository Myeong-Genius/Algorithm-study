#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int C, N, DP[1101], ans = 100001;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> C >> N;

    fill(DP, DP + 1101, 110001);
    DP[0] = 0;
    while(N--){
        int person, price;
        
        cin >> price >> person;
        for(int i = 0; i < C; i++){
            if(DP[i] == 110001) continue;
            for(int j = 1; i + person * j < 1101; j++){
                DP[i + person * j] = min(DP[i + person * j], DP[i] + price * j);
            }
        }
    }
    for(int i = C; i < 1101; i++) ans = min(ans, DP[i]);
    cout << ans;
    return 0;
}
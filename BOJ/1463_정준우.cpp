#include<iostream>
#include<vector>
using namespace std;

int DP[1000001], N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    DP[0] = DP[1] = 0;

    for(int i = 2; i <= N; i++){
        DP[i] = DP[i-1] + 1;
        if(i % 3 == 0) DP[i] = min(DP[i/3] + 1, DP[i]);
        if(i % 2 == 0) DP[i] = min(DP[i/2] + 1, DP[i]);
    }
    cout << DP[N];
    
    return 0;
}
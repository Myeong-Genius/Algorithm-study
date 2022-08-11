#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, arr[1000], dp[1000], dp2[1000];

void input(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

void fillIncreasingSeq(){
    dp[0] = 1;
    for (int i = 1; i < n; i++){
        int candidate = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                candidate = max(candidate, dp[j] + 1);
            }
        }
        dp[i] = candidate;
    }
}
void fillDecreasingSeq(){
    dp2[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--){
        int candidate = 1;
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                candidate = max(candidate, dp2[j] + 1);
            }
        }
        dp2[i] = candidate;
    }
}
void solve(){
    fillIncreasingSeq();
    fillDecreasingSeq();
    for(int i = 0; i < n; i++)
        dp[i] += dp2[i];
    cout << *max_element(dp, dp + n) - 1;
}

int main(){
    input();
    solve();
    return 0;
}
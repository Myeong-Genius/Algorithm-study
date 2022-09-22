#include<iostream>
using namespace std;
char s1[1001], s2[1001];
int dp[1001][1001], len1, len2;
void input();
void solve();
int main(){
    input();
    solve();
    return 0;
}
void input(){
    cin >> s1 >> s2;
}
void solve(){
    while(s1[++len1]){continue;}
    while(s2[++len2]){continue;}
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            }
        }
    }
    cout << dp[len1][len2];
}
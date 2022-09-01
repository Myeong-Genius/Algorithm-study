#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
struct{
    int weight, value;
}list_stuff [1000];
int dp[100001];

void input();
void solve();

int main(){
    input();
    solve();
    cout << endl;
    return 0;
}

void input(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> list_stuff[i].weight >> list_stuff[i].value;
    }
}

void solve(){
    for(int i = 0; i < n; i++){
        for(int j = k; j >= list_stuff[i].weight; j--){
            dp[j] = max(dp[j], dp[j - list_stuff[i].weight] + list_stuff[i].value);
        }
    }
    cout << dp[k];
}
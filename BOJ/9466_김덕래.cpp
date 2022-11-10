#include<iostream>
#include<algorithm>
using namespace std;

int answer, n, order;
int arr[100001], visited[100001];
bool finished[100001];
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
}
void dfs(int i){
    if(visited[i]){
        if(!finished[i]){
            answer -= order - visited[i] + 1 ;
        }
        return;
    }
    visited[i] = ++order;
    dfs(arr[i]);
    finished[i] = true;
}
void solve(){
    order = 0, answer = n;
    fill(visited + 1, visited + 1 + n, 0);
    fill(finished + 1, finished + 1 + n, 0);
    for(int i = 1; i <= n; i++)
        dfs(i);
    cout << answer << '\n';
}
int main(){
    int test;
    cin >> test;
    while(test--){
        input();
        solve();
    }
}
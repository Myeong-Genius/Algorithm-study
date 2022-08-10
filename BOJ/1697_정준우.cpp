#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int N, K, ans;
bool visited[100001];
queue<pair<int, int> > que;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    que.push({N, 0});
    visited[N] = true;
    while(!que.empty()){
        pair<int, int> cur;

        cur = que.front();
        que.pop();
        if(cur.first == K){
            ans = cur.second;
            break;
        }
        if(cur.first * 2 <= 100000 && !visited[cur.first * 2]){
            que.push({cur.first * 2, cur.second + 1});
            visited[cur.first * 2] = true;
        }
        if(cur.first + 1 <= 100000 && !visited[cur.first + 1]){
            que.push({cur.first + 1, cur.second + 1});
            visited[cur.first + 1] = true;
        }
        if(cur.first - 1 >= 0 && !visited[cur.first - 1]){
            que.push({cur.first - 1, cur.second + 1});
            visited[cur.first - 1] = true;
        }
    }
    cout << ans;
    return 0;
}
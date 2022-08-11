#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, k;
bool visit[100001];
void input(){
    cin >> n >> k;
}
void solve(){
    queue<pair<int,int>> q;
    q.push(make_pair(n, 0));
    visit[n] = true;
    while(!q.empty()){
        pair<int, int> x = q.front();
        q.pop();
        visit[x.first] = true;
        if(x.first == k){
            cout << x.second;
            return;
        }
        if(x.first > 0 && visit[x.first - 1] == false)
            q.push(make_pair(x.first - 1, x.second + 1));
        if(x.first < 100000 && visit[x.first + 1] == false)
            q.push(make_pair(x.first + 1, x.second + 1));
        if(x.first != 0 && x.first * 2 < 100001 && visit[x.first * 2] == false)
            q.push(make_pair(x.first * 2, x.second + 1));
    }
}

int main(){
    input();
    solve();
    return 0;
}
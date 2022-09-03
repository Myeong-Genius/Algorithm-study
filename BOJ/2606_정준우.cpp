#include<iostream>
using namespace std;

int N, M, ans = -1;
bool visited[100], GRAPH[100][100];
void dfs(int cur){
    ans++;
    visited[cur] = true;
    for(int i = 0; i < N; i++){
        if(visited[i] || !GRAPH[cur][i]) continue;
        dfs(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    while(M--){
        int node1, node2;
        
        cin >> node1 >> node2;
        GRAPH[node1 - 1][node2 - 1] = true;
        GRAPH[node2 - 1][node1 - 1] = true;
    }
    dfs(0);
    cout << ans;
    return 0;
}
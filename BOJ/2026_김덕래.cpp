#include<iostream>
using namespace std;

int answer, n_computer, n_edge, graph[101][101];
bool visit[101];

void input();
void dfs(int node);
void solve();

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> n_computer >> n_edge;
    for(int i = 0; i < n_edge; i++){
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1][n2] = graph[n2][n1] = true;
    }
}

void dfs(int node){
    visit[node] = true;
    for(int i = 1; i <= n_computer; i++){
        if(graph[node][i] && !visit[i]){
            answer++;
            dfs(i);
        }
    }
}

void solve(){
    dfs(1);
    cout << answer;
}
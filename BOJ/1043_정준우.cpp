#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[101];
bool true_graph[101], visited[101];
int N, M, people_cnt, person_num, ans;
void dfs(int pos){
    true_graph[pos] = true;
    visited[pos] = true;

    for(int i = 0; i < graph[pos].size(); i++){
        if(!visited[graph[pos][i]]) dfs(graph[pos][i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> people_cnt;
    ans = M;
    while(people_cnt--){
        cin >> person_num;
        true_graph[person_num + 49] = true;
    }
    for(int i = 0; i < M; i++){
        cin >> people_cnt;
        for(int j = 0; j < people_cnt; j++){
            cin >> person_num;
            graph[i].push_back(person_num + 49);
            graph[person_num + 49].push_back(i);
        }
    }
    for(int i = 0; i < N; i++){
        if(true_graph[50 + i] && !visited[50 + i]) dfs(50 + i);
    }
    for(int i = 0; i < M; i++){
        if(true_graph[i]) ans--;
    }
    cout << ans;
    return 0;
}
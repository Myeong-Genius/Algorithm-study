#include<iostream>
#include<vector>
using namespace std;

int n, m, order[1001];
bool graph[1001][1001];

void input();
bool is_finished();
void order_decision(int ord);
void solve();

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int src, dest;
        cin >> src >> dest;
        graph[src][dest] = true;
    }
}
bool is_finished(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j]) return false;
        }
    }
    return true;
}
void order_decision(int ord){
    vector<int> taken_class = vector<int>();
    for(int i = 1; i <= n; i++){
        bool flag = false;
        for(int j = 1; j <= n; j++){
            if(graph[j][i]){
                flag = true;
                break;
            }
        }
        if(!flag && order[i] == 0){
            taken_class.push_back(i);
            order[i] = ord;
        }
    }
    for(int i = 0; i < taken_class.size(); i++){
        for(int j = 1; j <= n; j++){
            graph[taken_class[i]][j] = false;
        }
    }
}
void solve(){
    int ord = 0;
    while(!is_finished()){
        order_decision(++ord);
    }
    for(int i = 1; i <= n; i++){
        if(order[i]){
            cout << order[i];
        }
        else{
            cout << ord + 1;
        }
        if(i != n){
            cout << " ";
        }
    }
}
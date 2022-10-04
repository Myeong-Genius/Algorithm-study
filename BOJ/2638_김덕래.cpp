#include<iostream>
using namespace std;
bool map[100][100], visited[100][100];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, m, h;

void solve();
bool empty();
void air_contact(int r, int c);
void input();

int main(){
    input();
    solve();
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            cin >> map[i][j];
        }
    }
}
void solve(){
    while(!empty()){
        fill(&visited[0][0], &visited[n][m], false);
        air_contact(0, 0);
        h++;
    }
    cout << h;
}
bool empty(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j]) return false;
        }
    }
    return true;
}
void air_contact(int r, int c){
    if(visited[r][c]){
        if(map[r][c]){
            map[r][c] = false;
        }
        return;
    }
    visited[r][c] = true;
    
    if(!map[r][c]){
        for(int i = 0; i < 4; i++){
            int new_r = r + dy[i], new_c = c + dx[i];
            if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m){
                air_contact(new_r, new_c);
            }
        }
    }
}
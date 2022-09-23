#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

queue<pair<int, pair<int, int> > > que;
bool in_air[100][100];
int N, M, ans, map[100][100], dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int y, int x, int time){
    in_air[y][x] = true;
    for(int i = 0; i < 4; i++){
        int dy, dx;

        dy = y + dir[i][0];
        dx = x + dir[i][1];

        if(dy < 0 || dy >= N || dx < 0 || dx >= M || map[dy][dx] >= time || in_air[dy][dx]) continue;
        dfs(dy, dx, time);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) que.push({1, {i, j}});
        }
    }
    while(!que.empty()){
        pair<int, int> pos = que.front().second;
        int cheese_cnt = 0, time = que.front().first;

        que.pop();
        if(ans != time){
            memset(in_air, 0, sizeof(in_air));
            dfs(0, 0, time);
            ans = time;
        }
        for(int i = 0; i < 4; i++){
            int dy, dx;

            dy = pos.first + dir[i][0];
            dx = pos.second + dir[i][1];

            if(in_air[dy][dx] && map[dy][dx] < time) cheese_cnt++;
        }
        if(cheese_cnt < 2) map[pos.first][pos.second]++, que.push({time + 1, pos});
    }
    cout << ans;
    return 0;
}
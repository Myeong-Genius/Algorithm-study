#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;

bool MAP[50][50];
int T, M, N, K;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int> > pos;

bool checkPos(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < M && MAP[y][x];
}
void dfs(int y, int x){
    int toY, toX; 
    MAP[y][x] = false;

    for(int i = 0; i < 4; i++){
        toY = y + dir[i][1];
        toX = x + dir[i][0]; 
        if(checkPos(toY, toX)) dfs(toY, toX);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    while(T--){
        int x, y, ans = 0;

        cin >> M >> N >> K;

        pos.clear();
        memset(MAP, 0, sizeof(MAP));
        while(K--){
            cin >> x >> y;
            MAP[y][x] = true;
            pos.push_back(make_pair(y, x));
        }
        for(int i = 0; i < pos.size(); i++){
            if(checkPos(pos[i].first, pos[i].second)){
                dfs(pos[i].first, pos[i].second);
                ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
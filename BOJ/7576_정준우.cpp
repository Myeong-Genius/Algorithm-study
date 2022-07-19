#include<iostream>
#include<queue>
using namespace std;

int M, N, H, ans;
int map[1000][1000];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Tomato{
    int y, x, cost;
    Tomato(int y, int x, int cost): y(y), x(x), cost(cost) {}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    queue<Tomato> tomato_bag;

    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) tomato_bag.push(Tomato(i, j, 0));
        }
    }
    while(!tomato_bag.empty()){
        Tomato tomato = tomato_bag.front();
        tomato_bag.pop();
        ans = tomato.cost;
        for(int i = 0; i < 4; i++){
            int y, x;

            y = dir[i][0] + tomato.y;
            x = dir[i][1] + tomato.x;
            if(y > -1 && y < N && x > -1 && x < M && map[y][x] == 0){
                map[y][x] = 1;
                tomato_bag.push(Tomato(y, x, tomato.cost + 1));
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                cout << "-1";
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int R, C, T, DUST_MAP[51][51], ADD_MAP[51][51], ans = 2;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<int> air_conditioner;
void dust_spread(){
    int dx, dy, spread_amount, pos_size;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(DUST_MAP[i][j] < 5) continue;
            spread_amount = DUST_MAP[i][j] / 5;
            for(int k = 0; k < 4; k++){
                dy = i + dir[k][0];
                dx = j + dir[k][1];

                if(dy > -1 && dy < R && dx > -1 && dx < C && DUST_MAP[dy][dx] != -1){
                    ADD_MAP[dy][dx] += spread_amount;
                    ADD_MAP[i][j] -= spread_amount;
                }
            }
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(DUST_MAP[i][j] == -1) continue;
            DUST_MAP[i][j] += ADD_MAP[i][j];
            ADD_MAP[i][j] = 0;
        }
    }
    spread_amount = 0;
    for(int i = 1; i < C; i++) swap(spread_amount, DUST_MAP[air_conditioner[0]][i]);
    for(int i = air_conditioner[0] - 1; i > -1; i--) swap(spread_amount, DUST_MAP[i][C - 1]);
    for(int i = C - 2; i > -1; i--) swap(spread_amount, DUST_MAP[0][i]);
    for(int i = 1; i < air_conditioner[0]; i++) swap(spread_amount, DUST_MAP[i][0]);

    spread_amount = 0;
    for(int i = 1; i < C; i++) swap(spread_amount, DUST_MAP[air_conditioner[1]][i]);
    for(int i = air_conditioner[1] + 1; i < R; i++) swap(spread_amount, DUST_MAP[i][C - 1]);
    for(int i = C - 2; i > -1; i--) swap(spread_amount, DUST_MAP[R - 1][i]);
    for(int i = R - 2; i > air_conditioner[1]; i--) swap(spread_amount, DUST_MAP[i][0]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> DUST_MAP[i][j];
            if(DUST_MAP[i][j] == -1) air_conditioner.push_back(i);
        }
    }
    while(T--) dust_spread();
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            ans += DUST_MAP[i][j];
        }
    }
    cout << ans;
    return 0;
}
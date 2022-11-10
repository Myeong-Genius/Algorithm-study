#include<iostream>
#include<cstring>
using namespace std;

int N, map[20][20], max_num;
void calc_max(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) max_num = max(max_num, map[i][j]);
    }
}
void swap_array(int (&temp_map)[20][20]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) swap(map[i][j], temp_map[i][j]);
    }
}
void rotate_array(int (&temp_map)[20][20]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map[i][j] = temp_map[j][N - i - 1];
        }
    }
}
void play_game(int remain){
    int temp_map[20][20];

    if(remain == 0){
        calc_max();
        return;
    }
    for(int i = 0; i < 4; i++){
        memset(temp_map, 0, sizeof(temp_map));
        for(int row = 0; row < N; row++){
            int prev_num = 0, idx = -1;
            for(int col = 0; col < N; col++){
                if(map[row][col] == 0) continue;
                if(prev_num == map[row][col]) temp_map[row][idx] *= 2, prev_num = 0;
                else temp_map[row][++idx] = prev_num = map[row][col];
            }
        }
        swap_array(temp_map);
        play_game(remain - 1);
        rotate_array(temp_map);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> map[i][j];
    }
    play_game(5);
    cout << max_num;
    return 0;
}
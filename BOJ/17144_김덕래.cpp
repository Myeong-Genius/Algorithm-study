#include<iostream>
#include<numeric>
using namespace std;

int row, col, time, answer;
int map[50][50];
int diff[50][50];
int up[2], down[2];
void input();
void solve();
void spread();
void circulate();

int main(){
    input();
    solve();
}

void input(){
    cin >> row >> col >> time;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> map[i][j];
            if(map[i][j] == -1){
                if(up[0] == 0){
                    up[0] = i, up[1] = j;
                }
                else{
                    down[0] = i, down[1] = j;
                }
            }
        }
    }
}

void solve(){
    while(time--){
        spread();
        circulate();
    }
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            answer += map[i][j];
        }
    }
    cout << answer + 2;
}

void spread(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j] > 0){
                if(i > 0 && map[i-1][j] != -1){
                    diff[i - 1][j] += map[i][j] / 5;
                    diff[i][j] -= map[i][j] / 5;
                }
                if(i < row - 1 && map[i+1][j] != -1){
                    diff[i + 1][j] += map[i][j] / 5;
                    diff[i][j] -= map[i][j] / 5;
                }
                if(j > 0 && map[i][j - 1] != -1){
                    diff[i][j - 1] += map[i][j] / 5;
                    diff[i][j] -= map[i][j] / 5;
                }
                if(j < col - 1 && map[i][j + 1] != -1){
                    diff[i][j + 1] += map[i][j] / 5;
                    diff[i][j] -= map[i][j] / 5;
                }
            }
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            map[i][j] += diff[i][j];
            diff[i][j] = 0;
        }
    }
}

void circulate(){
    int tmp = 0;
    for(int i = up[1] + 1; i < col - 1; i++){
        int tmp2 = map[up[0]][i];
        map[up[0]][i] = tmp;
        tmp = tmp2;
    }
    for(int i = up[0]; i > 0; i--){
        int tmp2 = map[i][col - 1];
        map[i][col - 1] = tmp;
        tmp = tmp2;
    }
    for(int i = col - 1; i > up[1]; i--){
        int tmp2 = map[0][i];
        map[0][i] = tmp;
        tmp = tmp2;
    }
    for(int i = 0; i < up[0]; i++){
        int tmp2 = map[i][0];
        map[i][0] = tmp;
        tmp = tmp2;
    }

    tmp = 0;
    for(int i = down[1] + 1; i < col - 1; i++){
        int tmp2 = map[down[0]][i];
        map[down[0]][i] = tmp;
        tmp = tmp2;
    }
    for(int i = down[0]; i < row - 1; i++){
        int tmp2 = map[i][col - 1];
        map[i][col - 1] = tmp;
        tmp = tmp2;
    }
    for(int i = col - 1; i > down[1]; i--){
        int tmp2 = map[row - 1][i];
        map[row - 1][i] = tmp;
        tmp = tmp2;
    }
    for(int i = row - 1; i > down[0]; i--){
        int tmp2 = map[i][0];
        map[i][0] = tmp;
        tmp = tmp2;
    }
}
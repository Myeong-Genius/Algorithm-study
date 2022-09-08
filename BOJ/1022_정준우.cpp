#include<iostream>
#include<iomanip>
using namespace std;

int NEW[50][5];
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int r1, r2, c1, c2, num, y, x, width, max_num, k, cnt, dir_cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r1 >> c1 >> r2 >> c2;
    num = 1;
    dir_cnt = 1;
    while(!NEW[0][0] || !NEW[0][c2 - c1] || !NEW[r2 - r1][c2 - c1] || !NEW[r2 - r1][0]){
        if(y >= r1 && y <= r2 && x >= c1 && x <= c2){
            NEW[y - r1][x - c1] = num;
            max_num = max(num, max_num);
        }
        y += dir[k][0];
        x += dir[k][1];
        cnt++, num++;
        if(cnt == dir_cnt){
            if(k % 2 == 1) dir_cnt++;
            k = (k + 1) % 4;
            cnt = 0;
        }
    }
    while(max_num > 0){
        max_num /= 10;
        width++;
    }
    for(int i = 0; i < (r2 - r1 + 1); i++){
        for(int j = 0; j < (c2 - c1 + 1); j++){
            if(j != 0) cout << ' ';
            cout << setw(width) << NEW[i][j];
        }
        cout << '\n';
    }
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int N, M, idx, min_bacon_cnt = 601;
int MAP[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    fill(MAP[0], MAP[100], 601); 
    cin >> N >> M;
    for(int i = 1; i <= N; i++) MAP[i][i] = 0;
    while(M--){
        int friend1, friend2;
        cin >> friend1 >> friend2;
        MAP[friend1][friend2] = 1;
        MAP[friend2][friend1] = 1;
    }
    for(int mid = 1; mid < N + 1; mid++){
        for(int i = 1; i < N + 1; i++){
            for(int j = 1; j < N + 1; j++){
                MAP[i][j] = min(MAP[i][j], MAP[i][mid] + MAP[mid][j]);
            }
        }
    }
    for(int i = 1; i < N + 1; i++){
        int bacon_cnt = 0;
        for(int j = 1; j < N + 1; j++) bacon_cnt += MAP[i][j];
        if(min_bacon_cnt > bacon_cnt) idx = i, min_bacon_cnt = bacon_cnt;
    }
    cout << idx;
    return 0;
}
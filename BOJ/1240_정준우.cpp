#include<iostream>
#include<vector>
using namespace std;

int MAP[1001][1001], N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < N + 1; j++){
            if(i == j) MAP[i][j] = 0;
            else{
                MAP[i][j] = 1000000001;
                MAP[j][i] = 1000000001;
            }
        }
    }
    for(int i = 0; i < N - 1; i++){
        int from, to, cost;

        cin >> from >> to >> cost;
        MAP[from][to] = cost;
        MAP[to][from] = cost;
    }

    for(int mid = 1; mid < N + 1; mid++){
        for(int i = 1; i < N + 1; i++){
            for(int j = 1; j < N + 1; j++){
                MAP[i][j] = min(MAP[i][j], MAP[i][mid] + MAP[mid][j]);
            }
        }
    }
    while(M--){
        int from, to;

        cin >> from >> to;
        cout << MAP[from][to] << '\n';
    }
    return 0;
}
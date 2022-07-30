#include <iostream>
#include<vector>
#include<queue>
#include <utility>
using namespace std;


int main() {
    int row, col, answer;
    queue<pair<int,int>> q;
    cin >> col >> row;
    vector<vector<int>> map(row, vector<int>(col));
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> map[i][j];
            if (map[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    // BFS
    while(q.empty() == false){
        int nx, ny;
        pair<int,int> cur = q.front();
        q.pop();
        
        for (int i=0; i<4; i++){
            ny = cur.first + dy[i];
            nx = cur.second + dx[i];
            if (0<=ny && 0<=nx && ny<row && nx<col && map[ny][nx]==0){
                map[ny][nx] = map[cur.first][cur.second] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    
    answer = 0;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if (map[i][j]==0){
                cout<< -1;
                return 0;
            }
            if (answer < map[i][j]){
                answer = map[i][j];
            }
        }
    }
        
    cout << answer - 1;
    return 0;
}

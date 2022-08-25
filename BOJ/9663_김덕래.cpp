#include<iostream>
using namespace std;

int n, answer;
int coordinate[15];

void input(){
    cin >> n;
}

bool isAssailable(int row1, int col1, int row2, int col2){
    return col1 == col2 || col1 - col2 == row1 - row2 || col1 - col2 == row2 - row1;
}

void place(int row, int col){
    if(row == n){
        answer++;
        return;
    }

    coordinate[row] = col;
    for(int i = 1; i <= n; i++){
        bool deployable;
        for(int j = 1; j <= row; j++){
            if(isAssailable(j, coordinate[j], row + 1, i)){
                deployable = false;
                break;
            }
            deployable = true;
        }
        if(deployable)  place(row + 1, i);
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
        place(1, i);
    }
    cout << answer;
}

int main(){
    input();
    solve();
    return 0;
}
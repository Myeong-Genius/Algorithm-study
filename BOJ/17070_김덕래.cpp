#include<iostream>
using namespace std;

enum Direction{
    HORIZONTAL,
    VERTICAL,
    DIAGONAL
};

struct Cooridinate{
    int row, col;
    bool operator==(Cooridinate c){
        return row == c.row && col == c.col;
    }
};

struct Pipe{
    Direction dir;
    Cooridinate loc;
};

int map[17][17];
int house_size, answer;
Cooridinate destination;

void input(){
    cin >> house_size;
    destination = {house_size, house_size};
    for(int i = 1; i <= house_size; i++){
        for(int j = 1; j <= house_size; j++){
            cin >> map[i][j];
        }
    }
}

void move(Pipe pipe){
    if(pipe.loc == destination){
        answer++;
        return;
    }
    int r = pipe.loc.row, c = pipe.loc.col;
    if(pipe.dir != HORIZONTAL && r < house_size && !map[r + 1][c])  move({VERTICAL, r + 1, c});
    if(pipe.dir != VERTICAL && c < house_size && !map[r][c + 1])  move({HORIZONTAL, r, c + 1});
    if(!map[r + 1][c] && !map[r][c + 1] && !map[r + 1][c + 1] && r < house_size && c < house_size)  move({DIAGONAL, r + 1, c + 1});
}

void solve(){
    move({HORIZONTAL, 1, 2});
    cout << answer;
}

int main(){
    input();
    solve();
    return 0;
}
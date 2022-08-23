#include<iostream>
using namespace std;

int N, ans, col[15];

bool promise(int col_num){
    for(int i = 0; i < col_num; i++){
        if(col[i] == col[col_num] || (col_num - i) == abs(col[col_num] - col[i])) return false;
    }
    return true;
}
void nQueen(int col_num){
    if(col_num == N) ans++;
    for(int i = 0; i < N; i++){
        col[col_num] = i;
        if(promise(col_num)) nQueen(col_num + 1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    nQueen(0);
    cout << ans;
    return 0;
}
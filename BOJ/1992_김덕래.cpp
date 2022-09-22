#include<iostream>
#include<string>
using namespace std;

int n;
char arr[64][64];

void input();
bool isCompressible(int r1, int c1, int r2, int c2);
string compress(int r1, int c1, int r2, int c2);
void solve();

int main(){
   input();
   solve();
   return 0;
}

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
}
bool isCompressible(int r1, int c1, int r2, int c2){
    bool flag;
    for(int k = 0; k < 2; k++){
        flag = true;
        for(int i = r1; i < r2 && flag; i++){
            for(int j = c1; j < c2 && flag; j++){
                if(arr[i][j] != k + '0'){
                    flag = false;
                }
            }
        }
        if(flag) break;
    }
    return flag;
}
string compress(int r1, int c1, int r2, int c2){
    string str("");
    if(isCompressible(r1, c1, r2, c2)){
        return str + arr[r1][c1];
    }
    else{
        return str + "(" + compress(r1, c1, r1 + (r2 - r1) / 2, c1 + (c2 - c1) / 2) + compress(r1, c1 + (c2 - c1) / 2, r1 + (r2 - r1) / 2, c2) 
        + compress(r1 + (r2 - r1) / 2, c1, r2, c1 + (c2 - c1) / 2) + compress(r1 + (r2 - r1) / 2, c1 + (c2 - c1) / 2, r2, c2) + ")";
    }
}
void solve(){
    cout << compress(0, 0, n, n);
}
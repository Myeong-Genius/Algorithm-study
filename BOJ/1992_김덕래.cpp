#include<iostream>
#include<string>
using namespace std;

int n;
char arr[64][64];

void input();
bool isCompressible(int r1, int c1, int r2, int c2);
void compress(int r1, int c1, int r2, int c2);
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
bool isCompressible(int r1, int c1, int width){
    for(int i = r1; i < r1 + width; i++){
        for(int j = c1; j < c1 + width; j++){
            if(arr[i][j] != arr[r1][c1]){
                return false;
            }
        }
    }
    return true;
}
void compress(int r1, int c1, int width){
    if(isCompressible(r1, c1, width)){
        cout << arr[r1][c1];
    }
    else{
        cout << "(";
        compress(r1, c1, width / 2);
        compress(r1, c1 + width / 2,  width / 2);
        compress(r1 + width / 2, c1, width / 2);
        compress(r1 + width / 2, c1 + width / 2, width / 2);
        cout << ")";
    }
}
void solve(){
    compress(0, 0, n);
}
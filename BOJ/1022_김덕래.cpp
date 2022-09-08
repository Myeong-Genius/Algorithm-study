#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int r1, c1, r2, c2, max_n;
int answer[50][6];

void input();
void solve();
bool isInBound();
bool isFilled();
void draw();
void print();

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> r1 >> c1 >> r2 >> c2;
}

void solve(){
    draw();
    print();
}
bool isInBound(int r, int c){
    return r <= max({r1, r2}) && r >= min({r1, r2}) && c <= max({c1, c2}) && c >= min({c1, c2});
}
bool isFilled(){
    int r = r2 - r1 + 1;
    int c = c2 - c1 + 1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!answer[i][j])  return false;
        }
    }
    return true;
}
void draw(){
    int s = 0, r = 0, c = 0, n = 1;
    if(isInBound(0, 0)){
            answer[-r1][-c1] = n;
    }
    r = 1, c = 1, s = 2;
    while(!isFilled()){
        for(int i = 0; i < s; i++){
            r--;
            n++;
            if(isInBound(r, c)){
                answer[r - r1][c - c1] = n;
                max_n = n;
            }
        }
        for(int i = 0; i < s; i++){
            c--;
            n++;
            if(isInBound(r, c)){
                answer[r - r1][c - c1] = n;
                max_n = n;
            }
        }
        for(int i = 0; i < s; i++){
            r++;
            n++;
            if(isInBound(r, c)){
                answer[r - r1][c - c1] = n;
                max_n = n;
            }
        }
        for(int i = 0; i < s; i++){
            c++;
            n++;
            if(isInBound(r, c)){
                answer[r - r1][c - c1] = n;
                max_n = n;
            }
        }
        c++, r++;
        s += 2;
    }
}

void print(){
    int r = r2 - r1 + 1;
    int c = c2 - c1 + 1;
    int digit = 0;
    while(max_n){
        max_n /= 10;
        digit++;
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << setw(digit) << answer[i][j] << " ";
        }
        cout<<'\n';
    }
}
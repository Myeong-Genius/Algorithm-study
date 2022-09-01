#include<iostream>
#include<algorithm>
using namespace std;

int r1, c1, r2, c2;
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
            answer[0 - r1][0 - c1] = n;
    }
    while(!isFilled()){
        for(int i = 0; i < s; i++){
            n++;
            if(isInBound(r, c)){
                answer[r - r1][c - c1] = n;
            }
            r--;
        }
        r++;
        for(int i = 0; i < s; i++){
            c--;
            n++;
            if(isInBound(r, c)){
                answer[r - r1][c - c1] = n;
            }
        }

        for(int i = 0; i < s; i++){
            r++;
            n++;
            if(isInBound(r, c)){
                answer[r - r1][c - c1] = n;
            }
        }
        for(int i = 0; i < s; i++){
            n++;
            c++;
            if(isInBound(r, c)){
                answer[r - r1][c - c1] = n;
            }
        }
        if(s==0) {r--;}
        c++;
        s += 2;
    }
}

void print(){
    int r = r2 - r1 + 1;
    int c = c2 - c1 + 1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << answer[i][j] <<" ";
        }
        cout<<'\n';
    }
}
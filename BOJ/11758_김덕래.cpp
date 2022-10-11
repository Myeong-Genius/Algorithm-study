#include<iostream>
#define ABOVE 1
#define ON 0
#define UNDER -1
using namespace std;

int x_[3], y_[3];
void input();
void solve();

int main(){
    input();
    solve();
    return 0;
}
void input(){
    int x, y;
    for(int i = 0; i < 3; i ++){
        cin >> x_[i] >> y_[i];
    }
}
void solve(){
    int ccw = (x_[1] - x_[0]) * (y_[2] - y_[0]) - (y_[1] - y_[0]) * (x_[2] - x_[0]);
    if(ccw > 0)
        cout << 1;
    else if (ccw == 0)
        cout << 0;
    else
        cout << -1;
}
#include<iostream>
#include<utility>
using namespace std;

int ccw;
pair<int, int> pos[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 3; i++){
        cin >> pos[i].first >> pos[i].second;
    }
    ccw = (pos[1].first - pos[0].first) * (pos[2].second - pos[0].second) - (pos[1].second - pos[0].second) * (pos[2].first - pos[0].first);
    if(ccw == 0) cout << '0';
    else if(ccw > 0) cout << '1';
    else cout << "-1";
    return 0;
}
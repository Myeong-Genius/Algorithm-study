#include<iostream>
using namespace std;

const int MAX_DIST = 10000000;
int n, m, a, b, c, map[100][100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) if(i != j) map[i][j] = MAX_DIST;
    }
    while(m--){
        cin >> a >> b >> c;
        a--, b--;
        map[a][b] = min(map[a][b], c);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                if(k == n - 1){
                   if(i == j || map[i][j] == MAX_DIST) cout << "0 ";
                   else cout << map[i][j] << ' ';
                }
            }
            if(k == n - 1) cout << '\n';
        }
    }
    return 0;
}
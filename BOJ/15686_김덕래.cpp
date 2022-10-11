#include<iostream>
using namespace std;

struct Coordinate{
    int x, y;
} chicken[13];

struct{
    Coordinate c;
    int dist[13];
} house[100];
int n, m, n_house, n_chicken, comb[13], answer =11111;

void input();
void combination(int depth, int next);
void solve();

int main(){
    input();
    solve();
    return 0;
}
void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int v;
            cin >> v;
            if(v == 1){
                house[n_house].c.x = i, house[n_house++].c.y = j;
            }
            else if(v == 2){
                chicken[n_chicken].x = i, chicken[n_chicken++].y = j;
            }
        }
    }
}
void combination(int depth, int next){
    if(depth == m){
        // for(int i = 0 ; i < m; i++)
        //     cout << comb[i] <<' ';
        // cout<<'\n';
        int d = 0;
        for(int i = 0; i < n_house; i++){
            int closest_chicken = 101;
            for(int j = 0; j < m; j++){
                closest_chicken = min(house[i].dist[comb[j]], closest_chicken);
            }
            d += closest_chicken;
        }
        // cout << d <<" ";
        answer = min(answer, d);
    }

    for(int i = next; i < n_chicken; i++){
        comb[depth] = i;
        combination(depth + 1, i + 1);
    }
}
void solve(){
    for(int i = 0; i < n_house; i++){
        for(int j = 0; j < n_chicken; j++){
            house[i].dist[j] = abs(house[i].c.x - chicken[j].x) + abs(house[i].c.y - chicken[j].y);
        }
    }
    combination(0, 0);
    cout << answer;
}
#include<iostream>
#include<vector>
using namespace std;

int N, M, ans;
vector<pair<int, int> > chicken_pos, home_pos;
void check_dist(vector<int> pos){
    int result = 0;

    for(int i = 0; i < home_pos.size(); i++){
        int short_path = 1e7;
        for(int j = 0; j < pos.size(); j++){
            short_path = min(short_path, 
                            abs(home_pos[i].first - chicken_pos[pos[j]].first) + abs(home_pos[i].second - chicken_pos[pos[j]].second));
        }
        result += short_path;
    }
    ans = min(ans, result);
}
void dfs(int start, vector<int> pos){
    if(pos.size() == M) check_dist(pos);
    
    for(int i = start; i < chicken_pos.size(); i++){
        pos.push_back(i);
        dfs(i + 1, pos);
        pos.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    ans = 1e7;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp;
            
            cin >> temp;
            if(temp == 1) home_pos.push_back({i, j});
            else if(temp == 2) chicken_pos.push_back({i, j});
        }
    }
    dfs(0, vector<int>());
    cout << ans;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

bool is_exist;
vector<int> graph[51];
int N, M, people_cnt, person_num, ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> people_cnt;
    ans = M;
    while(people_cnt--){
        cin >> person_num;
    }
    while(M--){
        cin >> people_cnt;
        for(int i = 0; i < people_cnt; i++){
            
        }
    }
    cout << ans;
    return 0;
}
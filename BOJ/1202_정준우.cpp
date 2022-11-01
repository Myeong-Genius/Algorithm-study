#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

long long ans;
priority_queue<int> pri_que;
pair<int, int> jewel_info[300000];
int N, K, idx, package_wei[300000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> jewel_info[i].first >> jewel_info[i].second;
    }
    sort(jewel_info, jewel_info + N);
    for(int i = 0; i < K; i++) cin >> package_wei[i];
    sort(package_wei, package_wei + K);
    for(int i = 0; i < K; i++){
        while(idx < N){
            if(jewel_info[idx].first > package_wei[i]) break;
            pri_que.push(jewel_info[idx++].second);
        }
        if(pri_que.empty()) continue;
        ans += pri_que.top();
        pri_que.pop();
    }
    cout << ans;
    return 0;
}
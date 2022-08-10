#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int N, DP[1500001];
vector<pair<int, int> > consult_list;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int dur, gain;

        cin >> dur >> gain;
        consult_list.push_back({dur, gain});
    }
    for(int i = N - 1; i >= 0; i--){
        DP[i] = DP[i + 1];
        if((i + consult_list[i].first) > N) continue;
        DP[i] = max(DP[i], DP[i + consult_list[i].first] + consult_list[i].second);
    }
    cout << DP[0];
    return 0;
}
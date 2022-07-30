#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int N, ans, end_time;
vector<pair<int, int> > time_pair;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    while(N--){
        int from, to;
        
        cin >> from >> to;
        time_pair.push_back(make_pair(to, from));
    }
    sort(time_pair.begin(), time_pair.end());
    for(int i = 0; i < time_pair.size(); i++){
        if(end_time > time_pair[i].second) continue;
        end_time = time_pair[i].first;
        ans++;
    }
    
    cout << ans;
    return 0;
}
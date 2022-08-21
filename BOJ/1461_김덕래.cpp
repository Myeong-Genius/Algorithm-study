#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, answer;
vector<int> neg(0), pos(0);

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if (tmp < 0){
            neg.push_back(tmp * -1);
        }
        else{
            pos.push_back(tmp);
        }
    }
}

void solve(){
    int idx = 0, longest = 0;
    if(!pos.empty()){
        sort(pos.begin(), pos.end());
        if(pos.size() % m){
            idx += pos.size() % m;
            answer += pos[idx - 1] * 2;
        }
        // cout << answer << endl;
        for(; idx < pos.size(); idx += m){
            int value = pos[idx + m -1];
            answer += value * 2;
            // cout << answer << endl;
        }
        longest = pos[pos.size() - 1];
    }
    idx = 0;
    if(!neg.empty()){
        sort(neg.begin(), neg.end());
        if(neg.size() % m){
            idx += neg.size() % m;
            answer += neg[idx - 1] * 2;
        }       
        // cout << answer << endl;
        for(; idx < neg.size(); idx += m){
            int value = neg[idx + m -1];
            answer += value * 2;
            // cout << answer << endl;
        }
        longest = max(longest, neg[neg.size() - 1]);
    }
    
    cout << answer - longest;
}
int main(){
    input();
    solve();
    return 0;
}
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N, ans;
vector<int> num_list;
map<int, int> num_cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;

        cin >> num;
        num_list.push_back(num);
        num_cnt[num]++;
    }
    if(num_list.size() > 2){
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                int sum = num_list[i] + num_list[j];
                
                // 숫자가 존재하지 않거나 이미 계산한 경우
                if(num_cnt[sum] == 0) continue;
                // 더하는 숫자 중 하나가 0이고 합이 1개만 존재하는 경우
                if(num_cnt[sum] == 1 && (num_list[i] == sum || num_list[j] == sum)) continue;
                // 0 + 0인 경우 중, 0이 배열에서 2개만 존재하는 경우
                if(num_list[i] == 0 && num_list[j] == 0 && num_cnt[sum] == 2) continue;
                ans += num_cnt[sum];
                num_cnt[sum] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
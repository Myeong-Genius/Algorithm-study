#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int> num_list;
bool checked[100001];
int T, N, student_num[100001], j, ans, pos;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        cin >> N;
        ans = 0;
        memset(checked, 0, sizeof(checked));
        for(int i = 1; i <= N; i++) cin >> student_num[i];
        for(int i = 1; i <= N; i++){
            if(checked[i]) continue;

            pos = i;
            while(!checked[pos]){
                checked[pos] = true;
                num_list.push_back(pos);
                pos = student_num[pos];
            }
            for(j = 0; j < num_list.size(); j++){
                if(num_list[j] == pos) break;
            }
            ans += j;
            num_list.clear();
        }
        cout << ans << '\n';
    }
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

struct Hello{
    int lost, gain;
};
int N;
Hello LJ[20];

int knapsack(int remain, int gain, int count){
    int ans = 0;
    if(count == N) return gain;
    else{
        int after_remain = remain - LJ[count].lost;

        if(after_remain > 0) ans = max(ans, knapsack(after_remain, gain + LJ[count].gain, count + 1));
        ans = max(ans, knapsack(remain, gain, count + 1));
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> LJ[i].lost;
    for(int i = 0; i < N; i++) cin >> LJ[i].gain;

    cout << knapsack(100, 0, 0);
    return 0;
}
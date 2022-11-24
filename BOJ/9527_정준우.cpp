#include<iostream>
using namespace std;

long long A, B, cnt[55];
long long get_cnt(long long num){
    long long ans = num & 1;

    for(int i = 54; i > 0; i--){
        if((num & (1LL << i)) == 0) continue;
        num -= (1LL << i);
        ans += cnt[i - 1] + (num + 1);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cnt[0] = 1;
    for(int i = 1; i < 55; i++) cnt[i] = cnt[i - 1] * 2 + (1LL << i);
    cin >> A >> B;
    cout << get_cnt(B) - get_cnt(A - 1);
    return 0;
}
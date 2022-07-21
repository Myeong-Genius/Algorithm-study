#include<iostream>
#include<algorithm>
using namespace std;

int T, M, N, x, y;

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x % y);
}
int lcm(int x, int y){
    return x * y / gcd(x, y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    while(T--){
        int ans = -1, lcm_num;
        
        cin >> M >> N >> x >> y;
        lcm_num = lcm(M, N);
        x = (M == x)? 0 : x;
        y = (N == y)? 0 : y;
        for(int i = (x > 0)? x : M; i <= lcm_num; i += M){
            if(i % M == x && i % N == y){
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
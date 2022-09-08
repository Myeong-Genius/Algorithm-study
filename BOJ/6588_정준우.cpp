#include<iostream>
using namespace std;

int n, a, b;
bool is_not_prime[1000001];
void check_prime(){
    is_not_prime[0] = is_not_prime[1] = true;
    for(int i = 2; i < 1000001; i++){
        if(is_not_prime[i]) continue;
        for(int j = 2; (i * j) < 1000001; j++) is_not_prime[i * j] = true;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    check_prime();
    while(1){
        cin >> n;
        if(n == 0) break;
        a = b = 0;
        for(int i = 3; i < 1000001; i++){
            if(!is_not_prime[i] && !is_not_prime[n - i]){
                a = i, b = n - i;
                break;
            }
        }
        if(a == 0 && b == 0) cout << "Goldbach's conjecture is wrong.\n";
        else cout << n << " = " << a << " + " << b << '\n';
    }
    return 0;
}

#include<iostream>
#include<cmath>
#define M 1234567891
using namespace std;

int N;
long long hash_res, r = 1;
char in;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> in;
        hash_res = (hash_res + (in - 'a' + 1) * r) % M;
        r = (r * 31) % M;
    }
    cout << hash_res;
    return 0;
}
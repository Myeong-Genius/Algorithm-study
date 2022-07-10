#include<iostream>
using namespace std;

int N, COUNT[501], cnt5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    for(int i = 2; i <= N; i++){
        if(i % 5 == 0) COUNT[i] = COUNT[i/5] + 1;
        cnt5 += COUNT[i];
    }
    cout << cnt5;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool flag;
vector<int> divisor;
int N, diff, remain, num[100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];
    sort(num, num + N);
    diff = num[N - 1] - num[0];
    for(int i = 2; i <= sqrt(diff); i++){
        if(diff % i != 0) continue;
        if(i != sqrt(diff)) divisor.push_back(diff / i);
        divisor.push_back(i);
    }
    divisor.push_back(diff);
    sort(divisor.begin(), divisor.end());
    for(int i = 0; i < divisor.size(); i++){
        flag = false;
        remain = num[0] % divisor[i];
        for(int j = 1; j < N; j++){
            if(num[j] % divisor[i] == remain) continue;
            flag = true;
            break;
        }
        if(!flag) cout << divisor[i] << ' ';
    }
    return 0;
}
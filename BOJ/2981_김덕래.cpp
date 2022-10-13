#include<iostream>
using namespace std;

void input();
int gcd(int a, int b);
void solve();
int n, arr[100], answer;

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

void solve(){

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(i == 0 && j == 1)
                answer = abs(arr[i] - arr[j]);
            else{
                int a = abs(arr[i] - arr[j]);
                if(a > answer){
                    answer = gcd(a, answer);
                }
                else{
                    answer = gcd(answer, a);
                }
            }
        }
    }
    for(int i = 2; i <= answer / 2; i++)
        if(answer % i == 0)
            cout << i << ' ';
    cout << answer;
}

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}
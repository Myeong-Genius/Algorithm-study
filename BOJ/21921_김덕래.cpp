#include<iostream>
#include<numeric>
using namespace std;

int answer, x, n, arr[250001], count_max_visit;
void input();
void solve();
int main(){
    input();
    solve();
    return 0;
}
void input(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void solve(){
    int visitor_xdays = accumulate(arr, arr + x, 0);
    for(int i = 0; i <= n - x; i++){
        if(answer == visitor_xdays){
            count_max_visit++;
        }
        else if(visitor_xdays > answer){
            answer = visitor_xdays;
            count_max_visit = 1;
        }
        if(i != n - x){
            visitor_xdays += arr[i + x] - arr[i];
        }
    }
    if(answer){
        cout << answer<< '\n';
        cout << count_max_visit;
    }
    else{
        cout << "SAD";
    }
}
#include<iostream>
#include<algorithm>
using namespace std;

int arr[2000], n, answer;
void input();
void solve();
int main(){
    input();
    solve();
    return 0;
}
void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}
void solve(){
    sort(arr,arr + n);
    for(int i = 0; i < n; i++){
        int target = arr[i];
        int s = 0, e = n - 1;
        while(s < e){
            if(i == s)  {s++;  continue;}
            if(i == e)  {e--;  continue;}
            if(arr[s] + arr[e] == target){
                answer++; break;
            }
            else if(arr[s] + arr[e] < target) s++;
            else  e--;
        }
    }
    cout << answer;
}
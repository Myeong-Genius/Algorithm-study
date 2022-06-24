#include<iostream>
#include<vector>
using namespace std;

vector<int> parts;
int N, M;

long long get_cut_sum(int hei){
    long long cut_sum = 0;
    for(int i = 0; i < N; i++) cut_sum += (parts[i] > hei)? parts[i] - hei : 0;
    return cut_sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int high = 0, low = 0, ans;

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        high = (high > temp)? high : temp;
        parts.push_back(temp);
    }

    while(low <= high){
        int mid = (low + high) / 2;
        long long cut_sum;
        
        cut_sum = get_cut_sum(mid);
        if(cut_sum == M){
            ans = mid;
            break;
        }
        else if(cut_sum > M){
            low = mid + 1;
            ans = mid;
        }
        else high = mid - 1;
    }
    cout << ans << endl;

    return 0;
}
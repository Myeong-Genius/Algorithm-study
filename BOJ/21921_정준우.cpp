#include<iostream>
using namespace std;

int N, X, duplicate, max_sum, part_sum[250000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        int part_val;
        cin >> part_sum[i];
        if(i != 0) part_sum[i] += part_sum[i - 1];
        part_val = part_sum[i];
        if(i >= X) part_val = part_sum[i] - part_sum[i - X];
        
        if(max_sum == part_val) duplicate++;
        else if(max_sum < part_val) max_sum = part_val, duplicate = 1;
    }
    if(max_sum == 0) cout << "SAD";
    else cout << max_sum << '\n' << duplicate;
    return 0;
}
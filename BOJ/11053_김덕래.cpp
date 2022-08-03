#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1000];


int main(){
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) cin >> sequence[i];
    for (int i = 0; i < n; i++){
        int index = n-1-i, value = sequence[n-1-i];
        vector<int> candidate(1,1);
        for(int j = index + 1; j < n; j++){
            if(sequence[j] > value){
                candidate.push_back(dp[sequence[j]] + 1);
            }
        }
        dp[value] = *max_element(candidate.begin(),candidate.end());
    }
    cout << *max_element(dp, dp+1000);
}
#include<iostream>
#include<vector>
using namespace std;

int N, K, DP[101][100001];
vector<pair<int, int> > product_list;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int weight, value;

        cin >> weight >> value;
        product_list.push_back({weight, value});
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j++){
            DP[i + 1][j] = DP[i][j];
            if(product_list[i].first <= j){
                DP[i + 1][j] = max(DP[i + 1][j], DP[i][j - product_list[i].first] + product_list[i].second);
            }
        }
    }
    cout << DP[N][K];
    return 0;
}
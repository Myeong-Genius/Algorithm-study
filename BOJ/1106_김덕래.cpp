#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct promotion{
    int cost;
    int effect;
};

int main(){
    int minimum;
    int rep;
    int answer;
    cin >> minimum >> rep;
    vector<promotion> promoInform(rep);
    double EperC = 0;
    for (int i = 0; i < rep; i++){
        int c,e;
        cin >> c >> e;
        if (e/c > EperC){
            EperC = (double)e / c;
        }
        promoInform[i].cost = c;
        promoInform[i].effect = e;
    }

    vector<vector<int>> dp(rep + 1, vector<int>(EperC * (int)(minimum / EperC) + 2, 0));

    for (int i = 1; i <= rep; i++){
        for (int j = 1; j < dp[i].size() ; j++){
            int cost = promoInform[i-1].cost;
            int effect = promoInform[i-1].effect;
            if (j < cost){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i][j-cost] + effect, dp[i-1][j]);
            }
        }
    }

    for (int j = 1; j < dp[0].size(); j++){
        if(dp[rep][j] >= minimum){
            answer =j;
            break;
        }
    }
    cout << answer;
    return 0;
}
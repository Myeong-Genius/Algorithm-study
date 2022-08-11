#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_INDEX 1500000

int dp[MAX_INDEX];
int n;
struct Consulting{
    int time;
    int pay;
};

vector<Consulting> schedule(0);

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        Consulting c;
        cin >> c.time >> c.pay;
        schedule.push_back(c);
    }
}

void solve(){
    for(int i = 0; i < n; i++){
        Consulting c = schedule[i];
        dp[i + c.time] = max(dp[i] + c.pay, dp[i + c.time]);
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }
    cout << dp[n];
}


int main( ){    
    input();
    solve();
    return 0;
}
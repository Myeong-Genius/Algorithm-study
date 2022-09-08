#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int dp[102][100002];
vector<pair<int, int> > wv;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int main() {
    cin >> N >> K;
    wv.push_back(make_pair(0, 0));
    for(int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        wv.push_back(make_pair(w, v));
    }
    sort(wv.begin(), wv.end(), compare);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(j - wv[i].first >= 0) {
                dp[i][j] = dp[i - 1][j - wv[i].first] + wv[i].second;
            }
            int maxValue = max(dp[i - 1][j], dp[i][j - 1]);
            if(maxValue > dp[i][j]) {
                dp[i][j] = maxValue;
            }
        }
    }
    cout << dp[N][K] << "\n";

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[1500001];
vector<int> T, P;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int t, p;
        cin >> t >> p;
        T.push_back(t);
        P.push_back(p);
    }

    for(int i = 0; i < N; i++) {
        cout << T[i] << " " << P[i] << endl;
    }

    return 0;
}
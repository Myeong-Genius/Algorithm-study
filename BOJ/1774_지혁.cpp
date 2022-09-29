#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
double ans;
double location[1001][2];
vector<int> connect[1001];

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        location[i + 1][0] = x;
        location[i + 1][1] = y;
    }
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }

    for(int i = 1; i <= N; i++) {
        if(connect[i].size() == 0) {
            double minimumDist = 9000000000000LL;
            int willConnect = 0;
            for(int j = 1; j <= N; j++) {
                if(connect[j].size() != 0) {
                    double currentDist = sqrt(pow(location[i][0] - location[j][0], 2) + pow(location[i][1] - location[j][1], 2));
                    if(minimumDist > currentDist) {
                        minimumDist = currentDist;
                        willConnect = j;
                    }
                }
            }
            ans += minimumDist;
            connect[i].push_back(willConnect);
        }
    }
    printf("%.2f\n", ans);

    return 0;
}
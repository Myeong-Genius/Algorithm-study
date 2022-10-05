#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, ans;
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if(tmp == 2) {
                chicken.push_back(make_pair(i, j));
            }
            else if(tmp == 1) {
                house.push_back(make_pair(i, j));
            }
        }
    }

    if(chicken.size() == M) {
        for(int i = 0; i < house.size(); i++) {
            int dist = 10000;
            for(int j = 0; j < chicken.size(); j++) {
                int cur_dist = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
                if(dist > cur_dist) {
                    dist = cur_dist;
                }
            }
            ans += dist;
        }
    }
    else {
        // 지워야 할 치킨 집이 있을 때 경우
    }

    cout << ans << "\n";

    return 0;
}
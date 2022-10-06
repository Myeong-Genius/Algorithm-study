#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, ans;
vector<pair<int, int> > chicken, house;
vector<pair<int, int> > select_chickens;
bool selected[13];

int calculateDistance(vector<pair<int, int> > chickens) {
    int sum = 0;

    for(int i = 0; i < house.size(); i++) {
        int dist = 10000;
        for(int j = 0; j < chickens.size(); j++) {
            int cur_dist = abs(chickens[j].first - house[i].first) + abs(chickens[j].second - house[i].second);
            if(dist > cur_dist) {
                dist = cur_dist;
            }
        }
        sum += dist;
    }

    return sum;
}

void select(int index, int count) {
    if(count == M) {
        int sum = calculateDistance(select_chickens);
        if(ans == 0) {
            ans = sum;
        }
        else {
            if(ans > sum) {
                ans = sum;
            }
        }
    }
    for(int i = index; i < chicken.size(); i++) {
        if(selected[i]) {
            continue;
        }
        selected[i] = true;
        select_chickens.push_back(chicken[i]);
        select(i, count + 1);
        selected[i] = false;
        select_chickens.pop_back();
    }
}

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
        ans = calculateDistance(chicken);
    }
    else {
        select(0, 0);
    }

    cout << ans << "\n";

    return 0;
}
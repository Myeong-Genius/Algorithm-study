#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// https://kimjingo.tistory.com/121 참고자료

int N, K, idx;
pair<int, int> list[300001];
int bag[300001];
priority_queue<int> pq;
long long answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> list[i].first >> list[i].second;
    }
    for(int i = 0; i < K; i++) {
        cin >> bag[i];
    }

    sort(list, list + N);
    sort(bag, bag + K);

    for(int i = 0; i < K; i++) {
        while(idx < N && bag[i] >= list[idx].first) {
            pq.push(list[idx].second);
            idx++;
        }
        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << "\n";

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://yabmoons.tistory.com/188 - 참고자료

int N, M, ans;
int parent[100001];
vector<pair<int, pair<int, int> > > edge;
vector<int> v;

int find_parent(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        return parent[x] = find_parent(parent[x]);
    }
}

void union_parent(int x, int y, int c) {
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) {
        return;
    }
    parent[y] = x;
    N--;
}

bool is_same_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if(x == y) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edge.push_back({C, {A, B}});
    }

    sort(edge.begin(), edge.end());
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < edge.size(); i++) {
        if(!is_same_parent(edge[i].second.first, edge[i].second.second)){
            union_parent(edge[i].second.first, edge[i].second.second, edge[i].first);
            v.push_back(edge[i].first);
        }
    }

    for(int i = 0; i < v.size() - 1; i++) {
        ans = ans + v[i];
    }
    cout << ans << "\n";

    return 0;
}
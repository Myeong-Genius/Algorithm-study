#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int graph[1001];
char univ_types[1001];
vector<pair<pair<int, int>, int> > edges;

int find_parent(int x) {
    if(graph[x] == x) {
        return x;
    }
    return graph[x] = find_parent(graph[x]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if(a < b) {
        graph[a] = b;
    }
    else {
        graph[b] = a;
    }
}

bool compare(pair<pair<int, int >, int > p1, pair<pair<int, int >, int > p2) {
    return p1.second < p2.second;
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        graph[i] = i;
        cin >> univ_types[i];
    }
    for(int i = 0; i < M; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        if(univ_types[s] != univ_types[e]) {
            edges.push_back({ {s, e}, d });
        }
    }

    sort(edges.begin(), edges.end(), compare);

    int ans = 0, cnt = 0;
    for(auto edge : edges) {
        int s = edge.first.first;
        int e = edge.first.second;
        int d = edge.second;

        if(find_parent(s) != find_parent(e)) {
            union_parent(s, e);
            ans += d;
            if(++cnt == N - 1) {
                cout << ans << "\n";
                return 0;
            }
        }
    }

    cout << "-1" << "\n";
    return 0;
}
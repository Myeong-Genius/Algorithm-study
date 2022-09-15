#include <iostream>
#include <vector>

using namespace std;

int N, M;
int in_degree[1001];
vector<int> graph[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    return 0;
}
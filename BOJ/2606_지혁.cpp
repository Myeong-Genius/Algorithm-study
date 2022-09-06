#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int C, N, result;
vector<int> computer[101];
bool check[101];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        computer[a].push_back(b);
        computer[b].push_back(a);
    }

    q.push(1);
    check[1] = true;
    while(!q.empty()) {
        int a = q.front();
        q.pop();
        for(int i = 0; i < computer[a].size(); i++) {
            int b = computer[a][i];
            if(!check[b]) {
                q.push(b);
                check[b] = true;
            }
        }
    }

    for(int i = 0; i <= C; i++) {
        if(check[i]) {
            result++;
        }
    }

    cout << result - 1 << "\n";

    return 0;
}
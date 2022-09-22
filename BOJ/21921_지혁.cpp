#include <iostream>
#include <vector>

using namespace std;

int N, X;
int V[250001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> X;
    for(int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        V[i] = V[i - 1] + tmp;
    }

    int ans = 0, count = 0;
    for(int i = 0; i <= N - X; i++) {
        int check = V[i + X] - V[i];
        if(check > ans) {
            ans = check;
            count = 1;
        }
        else if(check == ans) {
            count++;
        }
    }

    if(ans == 0) {
        cout << "SAD" << "\n";
    }
    else {
        cout << ans << "\n";
        cout << count << "\n";
    }

    return 0;
}
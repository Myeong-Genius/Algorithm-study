#include <iostream>
#include <vector>

using namespace std;

int N, X, ans, con;
vector<int> visitor;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> X;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        visitor.push_back(tmp);
    }

    for(int i = 0; i <= N - X; i++) {
        int sum = 0;
        for(int j = 0; j < X; j++) {
            sum += visitor[i + j];
        }
        if(ans < sum) {
            ans = sum;
            con = 1;
        }
        else if(ans == sum) {
            con++;
        }
    }

    if(ans == 0) {
        cout << "SAD" << "\n";
    }
    else {
        cout << ans << "\n";
        cout << con << "\n";
    }

    return 0;
}
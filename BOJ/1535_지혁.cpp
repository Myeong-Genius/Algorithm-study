#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> L, J;
int result = 0;

void bruteForce(int index, int life, int joy) {
    if(life <= 0 || index >= N) {
        if(life > 0) {
            if(result < joy) {
                result = joy;
            }
        }
        return;
    }
    bruteForce(index + 1, life - L[index], joy + J[index]);
    bruteForce(index + 1, life, joy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        L.push_back(x);
    }
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        J.push_back(x);
    }
    bruteForce(0, 100, 0);

    cout << result << endl;

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int A[2000];
bool check[2000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            for(int k = j + 1; k < i; k++) {
                if((A[i] == A[j] + A[k]) && !check[i]) {
                    check[i] = true;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(check[i]) {
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
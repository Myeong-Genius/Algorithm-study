#include <iostream>
#include <algorithm>

using namespace std;

int N, ans, val;
int A[2000];

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
        val = A[i];
        int left = 0, right = N - 1, sum;
        while(left < right) {
            sum = A[left] + A[right];
            if(sum == val) {
                if(left != i && right != i) {
                    ans++;
                    break;
                }
                else if(left == i) {
                    left++;
                }
                else if(right == i) {
                    right--;
                }
            }
            else if(sum < val) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}
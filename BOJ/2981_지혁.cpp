#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://pangsblog.tistory.com/62 - 참고자료

int N;
vector<int> arr, result;

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    int m = arr[1] - arr[0];
    for(int i = 2; i < N; i++) {
        m = gcd(m, arr[i] - arr[i - 1]);
    }

    for(int i = 1; i * i <= m; i++) {
        if(m % i == 0) {
            result.push_back(i);
            if(i != m / i) {
                result.push_back(m / i);
            }
        }
    }
    sort(result.begin(), result.end());

    for(int i = 1; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
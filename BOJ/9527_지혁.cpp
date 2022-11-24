#include <iostream>

using namespace std;

// 이건 도저히 못풀겠음 https://uyt8989.tistory.com/100

long long A, B;
long long power2[55];

long long get1(long long x) {
    long long ret = x & 1;

    for(int i = 54; i > 0; i--) {
        if(x & (1LL << i)) {
            ret += power2[i - 1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    power2[0] = 1;
    for(int i = 1; i < 55; i++) {
        power2[i] = power2[i - 1] * 2 + (1LL << i);
    }

    cout << get1(B) - get1(A - 1);

    return 0;
}
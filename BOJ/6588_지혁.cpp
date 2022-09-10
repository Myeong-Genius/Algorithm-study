#include <iostream>
#include <cmath>

using namespace std;

int n, a, b;

bool prime(int num) {
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        bool fail = true;
        cin >> n;
        if(n == 0) {
            break;
        }
        else {
            for(int i = 1; i < n / 2; i++) {
                a = 2 * i + 1;
                b = n - a;
                if(prime(a) && prime(b)) {
                    cout << n << " = " << a << " + " << b << "\n";
                    fail = false;
                    break;
                }
            }
        }
        if(fail) {
            cout << "Goldbach's conjecture is wrong." << "\n";
        }
    }
    
    return 0;
}
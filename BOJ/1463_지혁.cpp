#include <iostream>

using namespace std;

int result = 1000000;

int calculate(int n, int sum) {
    if(n == 1) {
        if(sum < result) {
            result = sum;
        }
        return 1;
    }
    else {
        if(n % 3 == 0) {
            calculate(n / 3, sum + 1);
        }
        if(n % 2 == 0) {
            calculate(n / 2, sum + 1);
        }
        calculate(n - 1, sum + 1);
    }
}

int main() {
    long long n;

    cin >> n;

    calculate(n, 0);

    cout << result << endl;

    return 0;
}
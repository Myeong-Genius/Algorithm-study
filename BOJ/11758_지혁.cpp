#include <iostream>

using namespace std;

int x1, y1, x2, y2, x3, y3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double result = (x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3) / 2;

    if(result > 0) {
        cout << "1" << "\n";
    }
    else if(result < 0) {
        cout << "-1" << "\n";
    }
    else {
        cout << "0" << "\n";
    }

    return 0;
}
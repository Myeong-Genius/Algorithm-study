#include <iostream>

using namespace std;

int allcase[1000001];

int main() {
    int n;

    cin >> n;

    allcase[0] = allcase[1] = 0;
    
    for(int i = 2; i <= n; i++) {
        allcase[i] = allcase[i - 1] + 1;
        if(i % 3 == 0) {
            allcase[i] = min(allcase[i / 3] + 1, allcase[i]);
        }
        if(i % 2 == 0) {
            allcase[i] = min(allcase[i / 2] + 1, allcase[i]);
        }
    }

    cout << allcase[n];

    return 0;
}
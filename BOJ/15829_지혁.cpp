#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int mod = 1234567891;

int main() {
    int l;
    string line;

    cin >> l;
    cin >> line;

    long long result = 0;
    long long indice = 1;
    
    for(int i = 0; i < l; i++) {
        result = (result + (line[i] - 'a' + 1) * indice) % mod;
        indice = (indice * 31) % mod;
    }

    cout << result;

    return 0;
}
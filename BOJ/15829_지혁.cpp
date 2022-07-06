#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int l;
    vector<char> string;

    cin >> l;

    for(int i = 0; i < l; i++) {
        char tmp;
        cin >> tmp;
        string.push_back(tmp);
    }

    long long result = 0;
    for(int i = 0; i < l; i++) {
        result += (string[i] - 'a' + 1) * pow(31, i);
    }

    cout << result;

    return 0;
}
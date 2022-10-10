#include <iostream>
#include <string>

using namespace std;

string input, explosion;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string tmp = "";
    cin >> input >> explosion;

    for(int i = 0; i < input.size(); i++) {
        tmp += input[i];
        if(tmp.size() > explosion.size()) {
            if(tmp[tmp.size() - 1] == explosion[explosion.size() - 1]) {
                if(tmp.substr(tmp.size() - explosion.size()) == explosion) {
                    tmp = tmp.substr(0, tmp.size() - explosion.size());
                }
            }
        }
        else if(tmp == explosion) {
            tmp = "";
        }
    }

    if(tmp.size() > 0) {
        cout << tmp << "\n";
    }
    else {
        cout << "FRULA" << "\n";
    }

    return 0;
}
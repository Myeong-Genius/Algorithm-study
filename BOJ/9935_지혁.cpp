#include <iostream>
#include <string>

using namespace std;

string input, explode;

bool explostion() {
    int index = 0;
    bool flag = false, has_same = false;

    if(input.size() > explode.size()) {
        for(int i = 0; i <= input.size() - explode.size(); i++) {
            if(input[i] == explode[0]) {
                for(int j = 1; j < explode.size(); j++) {
                    if(input[i + j] != explode[j]) {
                        break;
                    }
                    if(j == explode.size() - 1) {
                        has_same = true;
                    }
                }
                if(has_same) {
                    flag = true;
                    if(i == 0) {
                        input = input.substr(explode.size());
                    }
                    else if(i == input.size() - explode.size()) {
                        input = input.substr(0, input.size() - explode.size());
                    }
                    else {
                        string tmp1 = input.substr(0, i);
                        string tmp2 = input.substr(i + explode.size());
                        input = tmp1 + tmp2;
                    }
                    has_same = false;
                }
            }
        }
    }
    else {
        if(input == explode) {
            input = "";
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input >> explode;

    while(true) {
        bool check = explostion();
        if(!check) {
            break;
        }
    }

    if(input.size() != 0) {
        cout << input << "\n";
    }
    else {
        cout << "FRULA" << "\n";
    }

    return 0;
}
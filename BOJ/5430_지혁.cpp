#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int t;

    cin >> t;

    for(int i = 0; i < t; i++) {
        string command;
        vector<string> numbers;
        int n;

        cin >> command;
        cin >> n;

        string input;
        cin >> input;
        istringstream ss(input);

        string tmp;
        for(int j; j < n; j++) {
            getline(ss, tmp, ',');
            int length = tmp.size();

            if(tmp[0] == '[') {
                tmp = tmp.substr(1);
            }
            else if(tmp[length - 1] == ']') {
                tmp = tmp.substr(0, length - 2);
            }
            numbers.push_back(tmp);
        }

        for(int j; j < n; j++) {
            cout << numbers[j] << endl;
        }
    }

    return 0;
}
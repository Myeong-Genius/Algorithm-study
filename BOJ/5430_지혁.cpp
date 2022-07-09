#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std; 

int main() {
    int t;

    cin >> t;

    for(int i = 0; i < t; i++) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        string command, array;
        int n;
        deque<int> numbers;
        bool reverse = false;
        bool error = false;

        cin >> command;
        cin >> n;
        cin >> array;
        
        array = array.substr(1, array.length() - 2);
        istringstream ss(array);

        for(int j = 0; j < n; j++) {
            string tmpString;
            getline(ss, tmpString, ',');

            int tmpInt;
            stringstream ssInt(tmpString);
            ssInt >> tmpInt;
            numbers.push_back(tmpInt);
        }

        for(int j = 0; j < command.length(); j++) {
            if(command[j] == 'R') {
                reverse = !reverse;
            }
            if(command[j] == 'D') {
                if(numbers.size() == 0) {
                    error = true;
                    break;
                }
                else if(!reverse) {
                    numbers.pop_front();
                }
                else {
                    numbers.pop_back();
                }
            }
        }

        if(error) {
            cout << "error" << endl;
        }
        else if(numbers.size() == 0) {
            cout << "[" << "]" << endl;
        }
        else {
            cout << "[";
            if(reverse) {
                for(int j = numbers.size() - 1; j > 0; j--) {
                    cout << numbers[j] << ",";
                }
                cout << numbers[0];
            }
            else {
                for(int j = 0; j < numbers.size() - 1; j++) {
                    cout << numbers[j] << ",";
                }
                cout << numbers[numbers.size() - 1];
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int T;

int check_palindrome(string str) {
    for(int i = 0; i < str.size() / 2; i++) {
        if(str[i] != str[str.size() - i - 1]) {
            return i;
        }
    }
    return -1;
}

int check(string str) {
    int index = check_palindrome(str);

    if(index == -1) {
        return 0;
    }
    else {
        string front_str = str;
        string back_str = str;

        front_str.erase(index, 1);
        back_str.erase(str.size() - index - 1, 1);

        if(check_palindrome(front_str) == -1 || check_palindrome(back_str) == -1) {
            return 1;
        }
        else {
            return 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    for(int i = 0; i < T; i++) {
        string str;
        cin >> str;
        cout << check(str) << "\n";
    }

    return 0;
}
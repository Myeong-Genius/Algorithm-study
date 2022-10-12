#include <iostream>
#include <string>

using namespace std;

string docs;
int N, cursor, string_front, string_back;

void excute(string command) {
    if(command[0] == 'L') {
        if(cursor != 0) {
            cursor -= 1;
        }
    }
    else if(command[0] == 'D') {
        if(cursor != docs.size()) {
            cursor += 1;
        }
    }
    else if(command[0] == 'B') {
        if(cursor != 0) {
            docs.erase(cursor, cursor + 1);
        }
    }
    else if(command[0] == 'P') {
        string insert_char;
        docs.insert(cursor, insert_char + command[2]);
        cursor++;
    }
    cout << "docs : " << docs << ", cursor : " << cursor << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> docs >> N;
    cin.ignore();

    cursor = docs.size();
    for(int i = 0; i < N; i++) {
        string command;
        getline(cin, command);
        excute(command);
    }

    cout << docs << "\n";

    return 0;
}
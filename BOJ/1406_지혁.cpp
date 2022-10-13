#include <iostream>
#include <string>
#include <list>

using namespace std;

string docs;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> docs >> N;
    cin.ignore();

    list<char> li(docs.begin(), docs.end());
    auto cursor = li.end();

    for(int i = 0; i < N; i++) {
        string command;
        getline(cin, command);
        
        if(command[0] == 'L') {
            if(cursor != li.begin()) {
                cursor--;
            }
        }
        else if(command[0] == 'D') {
            if(cursor != li.end()) {
                cursor++;
            }
        }
        else if(command[0] == 'B') {
            if(cursor != li.begin()) {
                cursor--;
                cursor = li.erase(cursor);
            }
        }
        else if(command[0] == 'P') {
            li.insert(cursor, command[2]);
        }
    }

    for(auto cur = li.begin(); cur != li.end(); cur++) {
        cout << *cur;
    }
    cout << "\n";

    return 0;
}
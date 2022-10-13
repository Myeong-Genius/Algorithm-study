#include<iostream>
#include<string>
#include<stack>
using namespace std;

int N;
char op;
string input;
stack<char> prev_stk, next_stk;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i = 0; i < input.size(); i++) prev_stk.push(input[i]);
    cin >> N;
    while(N--){
        cin >> op;
        if(op == 'L' && !prev_stk.empty()) next_stk.push(prev_stk.top()), prev_stk.pop();
        if(op == 'D' && !next_stk.empty()) prev_stk.push(next_stk.top()), next_stk.pop();
        if(op == 'B' && !prev_stk.empty()) prev_stk.pop();
        if(op == 'P') cin >> op, prev_stk.push(op);
    }
    while(!prev_stk.empty()) next_stk.push(prev_stk.top()), prev_stk.pop();
    while(!next_stk.empty()) cout << next_stk.top(), next_stk.pop();
    return 0;
}
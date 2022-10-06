#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<char> stk;
string base, explode;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> base >> explode;
    for(int i = 0; i < base.size(); i++){
        stk.push(base[i]);
        if(stk.size() >= explode.size() && stk.top() == explode[explode.size() - 1]){
            stack<char> temp;

            for(int j = explode.size() - 1; j > -1; j--){
                if(stk.top() != explode[j]){
                    while(!temp.empty()) stk.push(temp.top()), temp.pop();
                    break;
                }
                temp.push(stk.top()), stk.pop();
            }
        }
    }
    if(stk.size() == 0) cout << "FRULA";
    else{
        string res;
        
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        for(int i = res.size() - 1; i > -1; i--) cout << res[i];
    }
    return 0;
}
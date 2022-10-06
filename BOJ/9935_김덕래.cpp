#include<iostream>
#include<string>
using namespace std;

string str, bomb;
char stack[1000001];
void inp();
void solve();

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    inp();
    solve();
    return 0;
}
void inp(){
    cin >> str ;
    cin >> bomb;
}
void solve(){
    
    int i_s = 0;
    for(int i = 0; i < str.length(); i++){
        bool boom = true;
        stack[i_s++] = str[i];
        if(stack[i_s - 1] == bomb[bomb.length() - 1]){
            for(int j = 0; j < bomb.length() - 1; j++){
                if(stack[i_s - bomb.length() + j] != bomb[j]){
                    boom = false;
                    break;
                }
            }
            if(boom){
                i_s -= bomb.length(); 
                stack[i_s] = '\0';
            }
        }
    }
    stack[i_s] = '\0';

    if(stack[0]=='\0')
        cout<<"FRULA";
    else
        cout<<stack;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
vector<string> v(0);

void input(){
    string str;
    cin >> n;
    cin.get();
    for(int i = 0; i < n; i++){
        cin >> str;
        v.push_back(str);
    }
}
bool isPseudo(string str, int left, int right){
    while(left < right){
        if(str[left] != str[right]){
            return false;
        }
        left++; right--;
    }
    return true;
}
int PalindromeCheck(string str){
    int left = 0;
    int right = str.length() - 1;
    while(left < str.length()){
        if(str[left] != str[right]){
            if(isPseudo(str, left + 1, right) ||isPseudo(str, left, right - 1)){
                return 1;
            }
            else{
                return 2;
            }
        }
        left++; right--;
    }
    return 0;
}


void solve(){
    for(int i = 0; i < n; i++){
        cout << PalindromeCheck(v[i]) << endl;
    }
}

int main(){
    input();
    solve();
    return 0;
}
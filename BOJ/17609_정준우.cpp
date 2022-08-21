#include<iostream>
#include<string>
using namespace std;

int T;
string in_string;
bool is_palindrome = true, is_p_palindrome = true;

void check_palindrome(int left, int right){
    if(left >= right) return;
    if(in_string[left] != in_string[right]){
        if(!is_palindrome) is_p_palindrome = false;
        else{
            is_palindrome = false;
            check_palindrome(left + 1, right);
            if(!is_p_palindrome){
                is_p_palindrome = true;
                check_palindrome(left, right - 1);
            }
        }
    }
    else check_palindrome(left + 1, right - 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        cin >> in_string;
        is_palindrome = true, is_p_palindrome = true;
        check_palindrome(0, in_string.size() - 1);
        if(is_palindrome) cout << 0;
        else if(is_p_palindrome) cout << 1;
        else cout << 2;
        cout << '\n';
    }
    return 0;
}
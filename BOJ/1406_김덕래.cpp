#include<iostream>
#include <list>
using namespace std;

std::list<char> str;

int main(){
    char c;
    int n;
    while((c = cin.get()) != '\n'){
        str.push_back(c);
    }

    auto it = str.end();
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'L'){
            if(it != str.begin()){
                --it;
            }
        }
        else if(c == 'D'){
            if(it != str.end()){
                ++it;
            }
        }
        else if(c == 'B'){
            if(it != str.begin()){
                --it;
                it = str.erase(it);
            }
        }
        else{
            cin >> c;
            str.insert(it, c);
            // if(it != str.begin())
            //     --it;
        }
    }
    for(it = str.begin(); it != str.end(); ++it){
        cout << *it;
    }
    return 0;
}
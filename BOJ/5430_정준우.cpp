#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<sstream>
using namespace std;

int T, N, dir;
stringstream stream;
string::size_type pos;
deque<string> num_list;
string cmd, ary, num;
bool isError;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;

    while(T--){
        num_list.clear();
        dir = 0;
        isError = false;

        cin >> cmd >> N >> ary;
        ary.erase(0, 1);
        ary.erase(ary.size() - 1);
        stream.str(ary);

        while(getline(stream, num, ',')){
            num_list.push_back(num);
        }
        for(int i = 0; i < cmd.size(); i++){
            if(cmd[i] == 'D'){
                if(num_list.empty()){
                    isError = true;
                    break;
                }
                (dir == 1)? num_list.pop_back() : num_list.pop_front();
            }
            else dir ^= 1;
        }
        if(isError) cout << "error\n";
        else{
            cout << '[';
            while(!num_list.empty()){
                string temp = (dir == 1)? num_list.back() : num_list.front();
                cout << temp;
                (dir == 1)? num_list.pop_back() : num_list.pop_front();
                if(!num_list.empty()) cout << ',';
            }
            cout << "]\n";
        }
    }
    return 0;
}
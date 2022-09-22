#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N;
vector<string> map;
string quad_tree(int y, int x, int width){
    int num = map[y][x];
    bool can_compress = true;

    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            if(map[y + i][x + j] != num){
                can_compress = false;
                break;
            }
        }
    }
    width /= 2;
    if(can_compress) return to_string(num - '0');
    return "(" + quad_tree(y, x, width) + quad_tree(y, x + width, width) +
            quad_tree(y + width, x, width) + quad_tree(y + width, x + width, width) + ")";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        string in_string;

        cin >> in_string;
        map.push_back(in_string);
    }
    cout << quad_tree(0, 0, N);
    return 0;
}
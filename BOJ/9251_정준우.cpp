#include<iostream>
#include<string>
using namespace std;

string src1, src2;
int LCS[1001][1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> src1 >> src2;
    for(int i = 0; i < src1.size(); i++){
        for(int j = 0; j < src2.size(); j++){
            if(src1[i] == src2[j]) LCS[i + 1][j + 1] = LCS[i][j] + 1;
            else LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]);
        }
    }
    cout << LCS[src1.size()][src2.size()];
    return 0;
}
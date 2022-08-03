#include<iostream>
using namespace std;
int last[10][101];
int divisor = 1000000000;
int main(){
    int n, answer = 0;
    cin >> n ;

    for (int i = 1; i <= 9; i++)    last[i][1] = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= 9; j++){
            if (j != 0)     last[j - 1][i + 1] = (last[j - 1][i + 1] + last[j][i]) % divisor;
            if (j != 9)     last[j + 1][i + 1] = (last[j + 1][i + 1] + last[j][i]) % divisor;
        }
    }
    for (int i = 0; i <= 9; i++)    answer = (answer + last[i][n]) % divisor;

    cout << answer;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 행 : 사람, 열 : 생명력
int maxJoy[21][100];

int main(){
    int n;
    int lifeLoss[20], joyGain[20];

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> lifeLoss[i];
    }
    for (int i = 0; i < n; i++){
        cin >> joyGain[i];
    }

    for(int i = 1; i <= n; i++){
        int joy = joyGain[i-1];
        int life = lifeLoss[i-1];
        for(int j = 1; j < 100; j++){
            if(j >= life){
                maxJoy[i][j] = max(maxJoy[i - 1][j - life] + joy, maxJoy[i-1][j]);
            }
            else{
                maxJoy[i][j] = maxJoy[i-1][j];
            }
        }
    }

    cout << *max_element(maxJoy[n],maxJoy[n]+100);
    return 0;
}
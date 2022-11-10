#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, biggest;
vector<vector<int> > map(20, vector<int>(20, 0));

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
}


vector<vector<int> > up(vector<vector<int> > arr){
    vector<vector<int> > n_arr = vector<vector<int> >(arr);

    for(int j = 0; j < n; j++){
        bool changed[20] = {false,};
        for(int i = 1; i < n; i++){
            for(int k = i; k > 0; k--){
                if(n_arr[k][j]){
                    if(n_arr[k-1][j] == n_arr[k][j]){
                        // cout << i <<j <<k << changed[k - 1] <<endl;
                        if(!changed[k - 1]){
                            n_arr[k-1][j] *=2;
                            n_arr[k][j] = 0;
                            changed[k - 1] = true;
                        }
                        break;
                    }
                    else if(n_arr[k-1][j] == 0){
                        n_arr[k - 1][j] = n_arr[k][j];
                        n_arr[k][j] = 0;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    biggest = *max_element(&n_arr[0][0], &n_arr[0][0] + 400);
    return n_arr;
}

vector<vector<int> > down(vector<vector<int> > arr){
    vector<vector<int> > n_arr = vector<vector<int> >(arr);

    for(int j = 0; j < n; j++){
        bool changed[20] = {false,};
        for(int i = n - 1; i >= 0; i--){
            for(int k = i; k < n - 1; k++){
                if(n_arr[k][j]){
                    if(n_arr[k + 1][j] == n_arr[k][j]){
                        // cout << i <<j <<k << changed[k - 1] <<endl;
                        if(!changed[k + 1]){
                            n_arr[k + 1][j] *=2;
                            n_arr[k][j] = 0;
                            changed[k + 1] = true;
                        }
                        break;
                    }
                    else if(n_arr[k + 1][j] == 0){
                        n_arr[k + 1][j] = n_arr[k][j];
                        n_arr[k][j] = 0;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    biggest = *max_element(&n_arr[0][0], &n_arr[0][0] + 400);
    return n_arr;
}

vector<vector<int> > left(vector<vector<int> > arr){
    vector<vector<int> > n_arr = vector<vector<int> >(arr);

    for(int i = 0; i < n; i++){
        bool changed[20] = {false,};
        for(int j = 1; j < n; j++){
            for(int k = j; k > 0; k--){
                if(n_arr[i][k]){
                    if(n_arr[i][k - 1] == n_arr[i][k]){
                        if(!changed[k - 1]){
                            n_arr[i][k - 1] *=2;
                            n_arr[i][k] = 0;
                            changed[k - 1] = true;
                        }
                        break;
                    }
                    else if(n_arr[i][k - 1] == 0){
                        n_arr[i][k - 1] = n_arr[i][k];
                        n_arr[i][k] = 0;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    biggest = *max_element(&n_arr[0][0], &n_arr[0][0] + 400);
    return n_arr;
}

vector<vector<int> > right(vector<vector<int> > arr){
    vector<vector<int> > n_arr = vector<vector<int> >(arr);

    for(int i = 0; i < n; i++){
        bool changed[20] = {false,};
        for(int j = n - 1; j >= 0; j--){
            for(int k = j; k < n - 1; k++){
                if(n_arr[i][k]){
                    if(n_arr[i][k + 1] == n_arr[i][k]){
                        if(!changed[k + 1]){
                            n_arr[i][k + 1] *=2;
                            n_arr[i][k] = 0;
                            changed[k + 1] = true;
                        }
                        break;
                    }
                    else if(n_arr[i][k + 1] == 0){
                        n_arr[i][k + 1] = n_arr[i][k];
                        n_arr[i][k] = 0;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    biggest = *max_element(&n_arr[0][0], &n_arr[0][0] + 400);
    return n_arr;
}

void explore(int depth, vector<vector<int> > arr){
    if(depth != 5){
        explore(depth + 1, up(arr));
        explore(depth + 1, down(arr));
        explore(depth + 1, left(arr));
        explore(depth + 1, right(arr));
    }
}

void solve(){
    explore(0, map);
    cout << biggest;
}
int main(){
    input();
    solve();
    map = down(map);
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
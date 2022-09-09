#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1000000
using namespace std;

bool nonPrimeCheck[MAX + 1];
vector<int> test;
vector<int> prime;
void input();
void eratos();
void solve();

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}

void input(){
    int n;
    do{
        cin >> n;
        test.push_back(n);
    }while(n);
    test.pop_back();
}

void eratos(){
    for(int i = 2; i <= MAX; i++){
        if(nonPrimeCheck[i])  continue;
        
        prime.push_back(i);
        for(int j = 2 * i; j <= MAX; j += i){
            nonPrimeCheck[j] = true;
        }
    }
}

void solve(){
    eratos();
    for(auto it = test.begin(); it != test.end(); ++it){
        bool flag = false;
        for(auto it2 = prime.begin(); it2 != prime.end() && *it2 < *it; ++it2){
            if(!nonPrimeCheck[*it - *it2]){
                flag = true;
                cout << *it << " = " << *it2 << " + " << *it - *it2 <<'\n';
                break;
            }
        }
        if(!flag) cout << "Goldbach's conjecture is wrong.\n";
    }
}
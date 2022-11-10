#include<iostream>
#include<algorithm>
#include<set>
#define MAX_INDEX 300000
using namespace std;

struct Jewel{
    int weight, value;
}jewel[MAX_INDEX];
bool compare(Jewel i, Jewel j){
    return i.value > j.value;
}
multiset<int> bag;

int n_jewel, n_bag;
long long answer;

void input(){
    cin >> n_jewel >> n_bag;
    for(int i = 0; i < n_jewel; i++){
        cin >> jewel[i].weight >> jewel[i].value;
    }
    for(int i = 0; i < n_bag; i++){
        int n;
        cin >> n;
        bag.insert(n);
    }
    sort(jewel, jewel + n_jewel, compare);
}
void solve(){
    for(int i = 0; i < n_jewel && !bag.empty() ; i++){
        auto it = bag.lower_bound(jewel[i].weight);
        if(it != bag.end()){
            answer += jewel[i].value;
            bag.erase(it);
        }
    }
    cout << answer;
}

int main(){
    input();
    solve();
    return 0;
}
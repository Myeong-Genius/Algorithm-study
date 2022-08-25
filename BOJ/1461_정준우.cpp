#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, pos, ans, vec_size, max_step;
vector<int> pos_book, neg_book;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> pos;
        if(pos > 0) pos_book.push_back(pos);
        else neg_book.push_back(-pos);
    }
    sort(pos_book.begin(), pos_book.end());
    sort(neg_book.begin(), neg_book.end());
    vec_size = pos_book.size();
    for(int i = (vec_size - 1) % M; i > -1 && i < vec_size; i += M){
        if(i == (vec_size - 1)) max_step = pos_book[i];
        ans += pos_book[i] * 2;
    }
    vec_size = neg_book.size();
    for(int i = (vec_size - 1) % M; i > -1 && i < vec_size; i += M){
        if(i == (vec_size - 1)) max_step = max(max_step, neg_book[i]);
        ans += neg_book[i] * 2;
    }
    ans -= max_step;
    cout << ans;
    return 0;
}
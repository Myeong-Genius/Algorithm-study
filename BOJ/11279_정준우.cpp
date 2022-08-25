#include<iostream>
#include<queue>
using namespace std;

int N, num;
priority_queue<int> heap;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while(N--){
        cin >> num;
        if(num != 0) heap.push(num);
        else{
            if(heap.size() == 0) cout << "0\n";
            else{
                cout << heap.top() << '\n';
                heap.pop();
            }
        }
    }
    return 0;
}
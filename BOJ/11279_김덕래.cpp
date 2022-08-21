#include<iostream>
#include<vector>
using namespace std;

int rep, heap[200001], capacity;
vector<int> arrIn(0);

void input(){
    int n;
    cin >> rep;
    for(int i = 0; i < rep; i++){
        cin >> n;
        arrIn.push_back(n);
    }
}
void output(){
    cout << "arr : ";
    for(int i = 1; i <= capacity; i++)
        cout << heap[i] <<" ";
    cout <<endl;
}

void swap(int idx1, int idx2){
    int tmp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = tmp;
}

void insert(int n){
    int idx = ++capacity;
    heap[capacity] = n;

    while(heap[idx] > heap[idx / 2] && idx != 1){
        swap(idx, idx / 2);
        idx /= 2;
    }
    // output();
}

int erase(){
    if(!capacity){
        return 0;
    }

    int n = heap[1], idx = 1;
    heap[1] = heap[capacity];
    heap[capacity--] = 0;

    while(idx < capacity && (heap[idx] < heap[idx * 2] || heap[idx] < heap[idx * 2 + 1])){
        if(heap[idx * 2] > heap[idx * 2 + 1]){
            swap(idx, idx * 2);
            idx = idx * 2;
        }
        else{
            swap(idx, idx * 2 + 1);
            idx = idx * 2 + 1;
        }
    }
    return n;
}

void solve(){
    for(int i = 0; i < rep; i++){
        if(arrIn[i] == 0){
            cout << erase() << '\n';
        }
        else{
            insert(arrIn[i]);
        }
    }
}

int main(){
    input();
    solve();
    return 0;
}
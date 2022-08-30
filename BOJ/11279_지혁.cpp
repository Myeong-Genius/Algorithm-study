#include <iostream>

using namespace std;

int N, x, end_point;
int heap[100001];

void push(int num) {
    end_point++;
    heap[end_point] = num;

    int child = end_point;
    int parent = child / 2;
    while(child > 1 && heap[parent] < heap[child]) {
        int tmp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = tmp;

        child = parent;
        parent = child / 2;
    }
}

int pop() {
    int result = heap[1];

    heap[1] = heap[end_point];
    end_point--;

    int parent = 1;
    int child = parent * 2;
    if(child + 1 <= end_point) {
        child = heap[child] > heap[child + 1] ? child : child + 1;
    }
    while(child <= end_point && heap[parent] < heap[child]) {
        int tmp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = tmp;

        parent = child;
        child = child * 2;
        if(child + 1 <= end_point) {
            child = heap[child] > heap[child + 1] ? child : child + 1;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x;
        if(x == 0) {
            if(end_point != 0) {
                cout << pop() << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
        else {
            push(x);
        }
    }

    return 0;
}
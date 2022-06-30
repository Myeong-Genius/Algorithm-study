#include <iostream>
#include <algorithm>

using namespace std;

long long calcutateTree(long long *data, long long n, long long pivot) {
    long long result = 0;

    for(long long i = 0; i < n; i++) {
        if(data[i] - pivot > 0) {
            result += data[i] - pivot;
        }
    }

    return result;
}

long long binary_search(long long *data, long long n, long long m) {
    long long low = 0;
    long long high = *max_element(data, data + n);
    long long mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(calcutateTree(data, n, mid) == m) {
            return mid;
        }
        else if(calcutateTree(data, n, mid) < m) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return high;
}

int main() {
    long long n, m, result;
    cin >> n >> m;
    
    long long tree[n];
    for(long long i = 0; i < n; i++) {
        cin >> tree[i];
    }

    result = (tree[0] + tree[n - 1]) / 2;

    cout << binary_search(tree, n, m) << endl;
    return 0;
}
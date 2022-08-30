#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, answer;
int book[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> book[i];
    }

    sort(book, book + N + 1);

    int pivot = 0;
    for(int i = 0; i <= N; i++) {
        if(book[i] == 0) {
            pivot = i;
            break;
        }
    }

    for(int i = 0; i < pivot; i += M) {
        answer += abs(book[i] * 2);
    }

    for(int i = N; i > pivot; i -= M) {
        answer += book[i] * 2;
    }

    answer -= max(abs(book[0]), abs(book[N]));

    cout << answer << "\n";

    return 0;
}
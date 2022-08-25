#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> book;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        book.push_back(tmp)
    }

    

    return 0;
}
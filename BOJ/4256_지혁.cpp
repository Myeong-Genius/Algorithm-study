#include <iostream>
#include <vector>

using namespace std;

// https://seokjin2.tistory.com/56 참고 자료

int T, n;
vector<int> preorder;
vector<int> inorder;

void post_order(int root, int start, int end) {
    for(int i = start; i < end; i++) {
        if(inorder[i] == preorder[root]) {
            post_order(root + 1, start, i);
            post_order(root + i + 1 - start, i + 1, end);
            cout << preorder[root] << " ";
        }
    }
} 

int main() {
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> n;
        preorder.clear();
        inorder.clear();

        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            preorder.push_back(tmp);
        }
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            inorder.push_back(tmp);
        }

        post_order(0, 0, n);
        cout << "\n";
    }
    return 0;
}
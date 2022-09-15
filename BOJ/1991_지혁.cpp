#include <iostream>

#define MAX 10000

using namespace std;

int N;
char tree[MAX];

void preorder(int key) {
    if(tree[key] != '\0') {
        cout << tree[key];
        preorder(key * 2 + 1);
        preorder(key * 2 + 2);
    }
}

void inorder(int key) {
    if(tree[key] != '\0') {
        inorder(key * 2 + 1);
        cout << tree[key];
        inorder(key * 2 + 2);
    }
}

void postorder(int key) {
    if(tree[key] != '\0') {
        postorder(key * 2 + 1);
        postorder(key * 2 + 2);
        cout << tree[key];
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        char value, left, right;
        cin >> value >> left >> right;
        
        if(value == 'A') {
            tree[0] = value;
            if(left != '.') {
                tree[1] = left;
            }
            if(right != '.') {
                tree[2] = right;
            }
        }
        else {
            for(int i = 0; i < MAX; i++) {
                if(value == tree[i]) {
                   if(left != '.') {
                        tree[2 * i + 1] = left;
                    }
                    if(right != '.') {
                        tree[2 * i + 2] = right;
                    } 
                }
            }
        }
    }

    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";

    return 0;
} 
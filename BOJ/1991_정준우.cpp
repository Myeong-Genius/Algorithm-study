#include<iostream>
using namespace std;

int N;
char TREE[26][2];
void preorder(char cur){
    if(cur == '.') return;
    cout << cur;
    preorder(TREE[cur - 'A'][0]);
    preorder(TREE[cur - 'A'][1]);
}
void inorder(char cur){
    if(cur == '.') return;
    inorder(TREE[cur - 'A'][0]);
    cout << cur;
    inorder(TREE[cur - 'A'][1]);
}
void postorder(char cur){
    if(cur == '.') return;
    postorder(TREE[cur - 'A'][0]);
    postorder(TREE[cur - 'A'][1]);
    cout << cur;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        char node_name;
        
        cin >> node_name;
        cin >> TREE[node_name - 'A'][0] >> TREE[node_name - 'A'][1];
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}
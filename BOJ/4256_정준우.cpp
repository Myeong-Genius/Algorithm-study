#include<iostream>
using namespace std;

int T, N, num, preorder[1001], inorder[1001];
void postorder(int pre_idx, int begin, int end){
    int in_idx = inorder[preorder[pre_idx]];

    if(begin < in_idx) postorder(pre_idx + 1, begin, in_idx - 1);
    if(in_idx < end) postorder(pre_idx + in_idx - begin + 1, in_idx + 1, end);
    cout << preorder[pre_idx] << ' ';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1; i <= N; i++) cin >> preorder[i];
        for(int i = 1; i <= N; i++){
            cin >> num;
            inorder[num] = i;
        }
        postorder(1, 1, N);
        cout << '\n';
    }
    return 0;
}
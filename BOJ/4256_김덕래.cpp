#include<iostream>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;

int preorder[1000], inorder[1000];
map<int, pair<int, int> > tree;
int pre_index, size_tree;

void input(){
    fill(inorder, inorder + 1000, 0);
    fill(preorder, preorder + 1000, 0);
    cin >> size_tree;
    for(int i = 0; i < size_tree; i++){
        cin >> preorder[i];
    }
    for(int i = 0; i < size_tree; i++){
        cin >> inorder[i];
    }
}

int sliceNcombine(int b_index, int e_index){
    int center = preorder[pre_index];
    int c_index;
    pair<int,int> children = make_pair(0,0);
    for(c_index = b_index; inorder[c_index] != center; c_index++) ;
    
    if(b_index < c_index){
        ++pre_index;
        children.first = sliceNcombine(b_index, c_index - 1);
    }
    if(c_index < e_index){
        ++pre_index;
        children.second = sliceNcombine(c_index + 1, e_index);
    }
    tree[center] = children;
    return center;
}

void postorder(int node){
    if(tree[node].first)  postorder(tree[node].first);
    if(tree[node].second)  postorder(tree[node].second);
    cout << node << ' ';
}

void solve(){
    pre_index = 0;
    sliceNcombine(0, size_tree - 1);
    postorder(preorder[0]);
    cout<< '\n';
}

int main(){
    int test;
    cin >> test;
    while(test--){
        input();
        solve();
    }
    return 0;
}


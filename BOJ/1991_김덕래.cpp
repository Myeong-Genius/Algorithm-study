#include<iostream>
#include<utility>
#include<map>
using namespace std;

int size_tree;
map<char, pair<char, char>> dict_node;


void input();
void preorder_traversal(char node);
void inorder_traversal(char node);
void postorder_traversal(char node);
void solve();

int main(){
    input();
    solve();
    return 0;
}

void input(){
    cin >> size_tree;
    for(int i = 0; i < size_tree; i++){
        char node, child1, child2;
        cin >> node >> child1 >> child2;
        dict_node[node] = make_pair(child1, child2);
    }
}


void preorder_traversal(char node){
    cout << node;
    if(dict_node[node].first != '.')
        preorder_traversal(dict_node[node].first);
    if(dict_node[node].second != '.')
        preorder_traversal(dict_node[node].second);
}

void inorder_traversal(char node){
    if(dict_node[node].first != '.')
        inorder_traversal(dict_node[node].first);
    cout << node;
    if(dict_node[node].second != '.')
        inorder_traversal(dict_node[node].second);
}

void postorder_traversal(char node){
    if(dict_node[node].first != '.')
        postorder_traversal(dict_node[node].first);
    if(dict_node[node].second != '.')
        postorder_traversal(dict_node[node].second);
    cout << node;
}

void solve(){
    preorder_traversal('A');
    cout << '\n';
    inorder_traversal('A');
    cout << '\n';
    postorder_traversal('A');
}

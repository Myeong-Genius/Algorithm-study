#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, A, B, C, part, cost, parent[100001];
vector<pair<int, pair<int, int> > > edge;
int get_parent(int x){
    if(parent[x] == x) return x;
    return parent[x] = get_parent(parent[x]);
}
bool union_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a == b) return false;
    if(a > b) parent[a] = parent[b];
    else parent[b] = parent[a];
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    part = N;
    for(int i = 0; i < N; i++) parent[i + 1] = i + 1;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> C;
        edge.push_back({C, {A, B}});
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++){
        if(part == 2) break;
        if(!union_parent(edge[i].second.first, edge[i].second.second)) continue;
        cost += edge[i].first;
        part--;
    }
    cout << cost;
    return 0;
}
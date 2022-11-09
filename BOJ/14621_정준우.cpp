#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans;
char type, school_type[1001];
int V, E, A, B, C, cnt, parent[1001];
vector<pair<int, pair<int, int> > > edge;
int get_parent(int idx){
    if(parent[idx] == idx) return idx;
    return parent[idx] = get_parent(parent[idx]);
}
bool union_parent(int left, int right){
    left = get_parent(left);
    right = get_parent(right);
    
    if(left == right) return false;
    if(left < right) parent[right] = left;
    else parent[left] = right;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> V >> E;
    for(int i = 1; i <= V; i++){
        cin >> type;
        school_type[i] = type;
        parent[i] = i;
    }
    while(E--){
        cin >> A >> B >> C;
        edge.push_back({C, {A, B}});
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++){
        if(school_type[edge[i].second.first] == school_type[edge[i].second.second]) continue;
        if(union_parent(edge[i].second.first, edge[i].second.second)){
            ans += edge[i].first;
            cnt++;
        }
        if(cnt == (V - 1)) break;
    }
    if(cnt != (V - 1)) cout << -1;
    else cout << ans;
    return 0;
}
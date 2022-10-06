#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

double ans;
pair<int, int> pos[1000];
int N, M, y, x, cnt, parent[1000];
vector<pair<double, pair<int, int> > > edge;
double get_dist(const pair<int, int>& left_pos, const pair<int, int>& right_pos){
    return sqrt(pow((long long)(left_pos.first - right_pos.first), 2) +  
                pow((long long)(left_pos.second - right_pos.second), 2));
}
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
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        pos[i] = {y, x};
        parent[i] = i;
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            edge.push_back({get_dist(pos[i], pos[j]), {i, j}});
        }
    }
    for(int i = 0; i < M; i++){
        int left, right;
        
        cin >> left >> right;
        left--, right--;
        if(union_parent(left, right)) cnt++;
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++){
        if(union_parent(edge[i].second.first, edge[i].second.second)){
            ans += edge[i].first;
            cnt++;
        }
        if(cnt == (N - 1)) break;
    }
    cout << fixed;
    cout.precision(2);
    cout << round(ans * 100) / 100;
    return 0;
}
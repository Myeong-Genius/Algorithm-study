#include<iostream>
#include<vector>
using namespace std;

int N, M, COUNT[1001];
vector<int> prerequisite[1001];
int get_prerequisite(int course_num){
    int prerequisite_cnt = 0;

    if(COUNT[course_num] != -1) return COUNT[course_num];
    for(int i = 0; i < prerequisite[course_num].size(); i++){
        prerequisite_cnt = max(prerequisite_cnt, get_prerequisite(prerequisite[course_num][i]));
    }
    return COUNT[course_num] = prerequisite_cnt + 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++) COUNT[i] = -1;
    for(int i = 0; i < M; i++){
        int pre, post;

        cin >> pre >> post;
        prerequisite[post].push_back(pre);
    }
    for(int i = 1; i <= N; i++) cout << get_prerequisite(i) << ' ';
    return 0;
}
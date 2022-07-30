#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

struct edge{
    int dest;
    int distance;
};

vector<vector<edge>> graph;
vector<bool> visit;
int answer;
bool dfs(int visiting, int dest){
    if (dest == visiting){
        return true;
    }
    
    visit[visiting] = true;
    for (int i = 0; i < graph[visiting].size(); i++){
        int otherNode = graph[visiting][i].dest;
        if (visit[otherNode] == false){
            if (dfs(otherNode, dest)){
                answer += graph[visiting][i].distance;
                return true;
            }
        }
    }
    
    return false;
    
}

int main(){
    int rep1, rep2;
    cin >> rep1 >> rep2;
    graph.resize(rep1 + 1);
    visit.resize(rep1 + 1);
    for (int i = 0; i < rep1 - 1; i++){
        int n1, n2, d;
        edge e1, e2;
        cin >> n1 >> n2>> d;
        e1.distance = e2.distance = d;
        e1.dest = n2;   e2.dest = n1;
        graph[n1].push_back(e1);    graph[n2].push_back(e2);
    }
    
    for (int i = 0; i < rep2; i++){
        visit.assign(rep1 + 1, false);
        answer = 0;
        int start, end;
        cin >> start >> end;
        dfs(start, end);
        cout << answer << endl;
    }
    return 0;
}
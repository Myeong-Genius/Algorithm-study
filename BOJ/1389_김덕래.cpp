#include <iostream>
#include<vector>
#include<queue>
#include <numeric>
using namespace std;


int main() {
    int nodes, edges, n1, n2, bacon=100, answer, dist;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes+1);
    vector<int> distance(nodes+1);
    // vector<bool> visited(nodes+1);
    queue<int> q;
    
    // Create a graph 
    for (int i = 0; i < edges; i++){
        cin >> n1 >> n2 ;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    
    for(int i = 1; i <= nodes; i++){
        distance.assign(nodes+1, -1);
        q.push(i);
        distance[i] = 0;
        
        // BFS
        while(q.empty() == false){
            int cur = q.front();
            q.pop();
            
            for(int j = 0; j < graph[cur].size(); j++){
                int next = graph[cur][j];
                if(distance[next] == -1){
                    q.push(next);
                    distance[next] = distance[cur] + 1;
                }
            }
        }
        
        // Sum up elements
        dist = accumulate(distance.begin(), distance.end(), 0);
        
        // Compare dist with bacon(shortest dist ever)
        if (dist < bacon){
            answer = i;
            bacon = dist;
        }
        
        
    }

    cout << answer;
    return 0;
}

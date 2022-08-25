#include<iostream>
#include<vector>
using namespace std;

int nPeople, nParty, answer;
bool graph[51][51];
bool visited[51];
bool knowTruth[51];
vector<vector<int>> party;

void saveTruth(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int n2;
        cin >> n2;
        knowTruth[n2] = true;
    }
}

void saveAttendee(){
    for(int i = 0; i < nParty; i++){
        int n;
        cin >> n;
        vector<int> attendee(n);
        for(int j = 0; j < n; j++){
            cin >> attendee[j];
        }
        party.push_back(attendee);
    }
}

void graphConnection(){
    for(vector<int> attendee : party){
        for(int p1 : attendee){
            for(int p2 : attendee){
                graph[p1][p2] = graph[p2][p1] = true;
            }
        }
    }
}

void renew(int node){
    knowTruth[node] = visited[node] = true;
    for(int i = 1; i <=nPeople; i++){
        if(i == node) continue;
        if(graph[node][i] && !visited[i])  renew(i);
    }
}

void renewTruth(){
    for(int i = 1; i <= nPeople; i++){
        if(knowTruth[i]){
            renew(i);
        }
    }
}

bool canSheLie(vector<int> attendee){
    for(int person : attendee){
        if(knowTruth[person])  return false;
    }
    return true;
}

void input(){
    cin >> nPeople >> nParty;
    saveTruth();
    saveAttendee();
}

void solve(){
    graphConnection();
    renewTruth();
    for(vector<int> attendee : party){
        if(canSheLie(attendee))  answer++;
    }
    cout << answer;
}

int main(){
    input();
    solve();
    return 0;
}
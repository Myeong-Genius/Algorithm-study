#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

bool compare(tuple<int, int> m1, tuple<int, int> m2){
    int e1 = get<1>(m1), e2 = get<1>(m2);
    if (e1 == e2){
        int s1 = get<0>(m1), s2 = get<0>(m2);
        return s1 < s2;
    }
    else
        return e1 < e2;
}

int main(){
    int requests, answer = 0, end = 0;
    cin >> requests;
    vector<tuple<int, int>> meetings;
    for (int i = 0; i < requests; i++){
        int start, end;
        cin >> start >> end;
        auto meeting = make_tuple(start, end);
        meetings.push_back(meeting);
    }
    sort(meetings.begin(), meetings.end(), compare);

    for (int i = 0; i < requests; i++){
        auto meeting = meetings[i];
        if (end <= get<0>(meeting)){
            answer++;
            end = get<1>(meeting);
        }
    }
    cout << answer;
}
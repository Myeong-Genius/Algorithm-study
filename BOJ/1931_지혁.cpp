#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<pair<int, int> > v;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int s, e;
        cin >> e >> s;
        pair<int, int> tmp = make_pair(s, e);

        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    
    int previous = v.front().first;
    int result = 1;
    for(int i = 1; i < N; i++) {
        if(previous <= v[i].second) {
            result++;
            previous = v[i].first;
        }
    }

    cout << result << endl;

    return 0;
}
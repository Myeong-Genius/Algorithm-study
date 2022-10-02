#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int parent[1010];
double ans;
vector<pair<int, int> > coord;
vector<pair<int, int> > connect;
vector<pair<double, pair<int, int> > > edge;

int findParent(int n) {
    if(n == parent[n]) {
        return n;
    }
    return parent[n] = findParent(parent[n]);
}

bool sameParent(int n, int m) {
    n = findParent(n);
    m = findParent(m);
    if(n == m) {
        return true;
    }
    else {
        return false;
    }
}

void unionNM(int n, int m) {
    n = findParent(n);
    m = findParent(m);
    parent[m] = n;
}

double findDistance(int x1, int y1, int x2, int y2) {
    double dx = pow(x1 - x2, 2);
    double dy = pow(y1 - y2, 2);
    double dist = sqrt(dx + dy);
    return dist;
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coord.push_back(make_pair(x, y));
    }
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        connect.push_back(make_pair(x, y));
    }

    for(int i = 0; i < M; i++) {
        int n1 = connect[i].first;
        int n2 = connect[i].second;

        if(!sameParent(n1, n2)) {
            unionNM(n1, n2);
        }
    }
    for(int i = 0; i < N - 1; i++) {
        int x1 = coord[i].first;
        int y1 = coord[i].second;

        for(int j = i + 1; j < N; j++) {
            int x2 = coord[j].first;
            int y2 = coord[j].second;

            double dist = findDistance(x1, y1, x2, y2);
            edge.push_back(make_pair(dist, make_pair(i + 1, j + 1)));
        }
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++) {
        int n1 = edge[i].second.first;
        int n2 = edge[i].second.second;
        double dist = edge[i].first;

        if(!sameParent(n1, n2)) {
            unionNM(n1, n2);
            ans += dist;
        }
    }

    printf("%.2f\n", ans);

    return 0;
}
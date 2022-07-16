#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    for(int i = 0; i < t; i++) {
        int array0[41], array1[41];
        array0[0] = array1[1] = 1;
        array0[1] = array1[0] = 0;

        cin >> n;

        for(int j = 0; j < n - 1; j++) {
            array0[j + 2] = array0[j + 1] + array0[j];
            array1[j + 2] = array1[j + 1] + array1[j];
        }
        
        cout << array0[n] << " " << array1[n] << endl;
    }

    return 0;
}
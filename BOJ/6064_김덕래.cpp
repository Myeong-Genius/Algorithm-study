#include <iostream>
using namespace std;

int gcd(int a, int b){
    return (b==0) ? a : gcd(b, a % b);
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}


int main(){
    int rep, m, n, x, y;
    cin >> rep;
    for (int i = 0; i < rep; i++){
        cin >> m >> n >> x >> y;
        x--; y--;
        int max = lcm(m, n);
        int year = x;
        while(year <= max && year % n != y){
            year += m;
        }
        if (year > max)
            cout << -1 << endl;
        else
            cout << year + 1 << endl;
        
    }
    return 0;
}
#include <iostream>

using namespace std;

int r1, c1, r2, c2, m, s;
int a[50][50];

int main() {
    cin >> r1 >> c1 >> r2 >> c2;

    for(int i = r1; i <= r2; i++) {
		for(int j = c1; j <= c2; j++) {
			int x = i - r1, y = j - c1;
			if(i - j < 0) {
				if(i + j < 0) {
                    			a[x][y] = 4 * i * i + i + 1 - j;
                		}
				else {
                    			a[x][y] = 4 * j * j - 3 * j + 1 - i;
                		}
			}
			else {
				if(i + j < 0) {
                    			a[x][y] = 4 * j*j - j + 1 + i; 
                		}
				else {
                    			a[x][y] = 4 * i*i + 3 * i + 1 + j;
                		}
			}
			if(a[x][y] > m) {
                		m = a[x][y];
            		}
		}
	}

    for(; m; m /= 10) {
        s++;
    }
	for(int i = 0; i <= r2 - r1; i++) {
		for(int j = 0; j <= c2 - c1; j++) {
            		printf("%*d ", s, a[i][j]);
        	}
		puts("");
	}

    return 0;
}

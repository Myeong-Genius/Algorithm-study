#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct promotion{
    int cost, effect;
};

int maxByMoney[100001];

int main(){
    int minimum, cities, i;
    cin >> minimum >> cities;
    vector<promotion> promo(cities);
    for (i = 0; i < cities; i++){
        cin >> promo[i].cost >> promo[i].effect;
    }

    for (i =0; i < cities; i++){
        int cost = promo[i].cost, effect = promo[i].effect;
        for (int j =1; maxByMoney[j-1] < minimum; j++){
            if (j >= cost)
                maxByMoney[j] = max(maxByMoney[j - cost] + effect, maxByMoney[j]);
        }
    }
    for(i = 0; maxByMoney[i] < minimum ; i++){
        continue;
    }
    
    cout << i;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long costFn(vector<int> cost, int index, int money_left){

    if(index >= cost.size()) return 0;

    long long k;

    if(cost[index] <= money_left){
        long a = pow(2, index) + costFn(cost, index + 1, money_left - cost[index]);
        long b = costFn(cost, index + 1, money_left);
        k = max(a, b);
    }
    else
    {
        k = costFn(cost, index + 1, money_left);
    }

    return k;
}



int main(){

    cout << costFn({10, 20, 14, 40, 50}, 0, 70) << "\n";

    return 0;
}



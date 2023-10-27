#include <bits/stdc++.h>

using namespace std;


int cashBack(int p, int q){


    if(p == q) return 0;

    if(q == 0) return 1;
    if(q == 1) return 1;
    if(p > q) return -1;

    int a = INT_MAX, b = INT_MAX;

    if(q%2 == 0){
        a = 1 + cashBack(p, q/2);
    }

    int k = sqrt(q);

    if(k * k == q){
        b = 1 + cashBack(p, k);
    }

    return min(a, b);

}



int main()
{


}

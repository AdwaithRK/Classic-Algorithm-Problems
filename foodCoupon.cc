#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> coins = {1, 4, 10};

    int ans = 0, sum = 0, P = 19;

    for(int  i = 1; i <= P; i++){

        if(find(coins.begin(), coins.end(), i) != coins.end()){
            sum += i;
        }
        else if(sum < i){
            sum += i;
            ans++;
        }

    }

    cout << "answer : " << ans << "\n";


    return 0;
}
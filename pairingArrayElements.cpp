#include<bits/stdc++.h>

using namespace std;

int countPairs(vector<int> ans){

    int evenNumberCount = 0;
    int oddNumberCount = 0;

    for(int i = 0; i < ans.size(); i++){

        if(ans[i] % 2 == 0) evenNumberCount++;
        else
            oddNumberCount++;
    }

    return (evenNumberCount/2) + (oddNumberCount/2);
}


int main(){

    vector<int>  ans = {1, 2, 3, 4, 5, 6, 7, 11};

    int result = countPairs(ans);

    cout << "answer : " << result << "\n";

    return 0;

}
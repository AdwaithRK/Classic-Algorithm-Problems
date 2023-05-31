#include<bits/stdc++.h>

using namespace std;

vector<vector<bool>> DP(4, vector<bool>(11, false));


int main(){
    vector<int> ss = {1,2,7};
    int sum = 0;
    
    for(int i = 0; i < ss.size(); i++){
        sum += ss[i];
    }

    cout << "sum : " << sum << "\n";

    for(int j = 0; j <= sum; j++){
        DP[0][j] = false;
    }


    for(int i = 0; i <= ss.size(); i++){
        DP[i][0] = 1;
    }

    for(int i = 0; i <= ss.size(); i++){
        for(int j = 0; j <= sum; j++){
            cout << DP[i][j] << "\t";        
        }
        cout << "\n";
    }


    cout << "\n\n";

    for(int i = 1; i <= ss.size(); i++){
        for(int j = 1; j <= sum; j++){
            if(ss[i-1] < j){
                DP[i][j] = DP[i-1][j - ss[i-1]] || DP[i-1][j];
            }else{
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    for(int i = 0; i <= ss.size(); i++){
        for(int j = 0; j <= sum; j++){
            cout << DP[i][j] << "\t";        
        }
        cout << "\n";
    }

    vector<int> result;

    for(int k = 0; k <= sum/2; k++){
        if(DP[3][k]) result.push_back(k);
    }



    // for(int i = 0; i < result.size(); i++){
    //     cout << result[i] << "\n";
    // }

    return 0;

}
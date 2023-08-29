#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A = "fabcdei";
    string B = "kabceikkkkk";

    vector<vector<int>> DP(A.size() + 1, vector<int>(B.size() + 1, -1));

    for (int i = 0; i <= A.size(); i++)
    {
        for (int j = 0; j <= B.size(); j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
        }
    }



    for(int i = 1; i <= A.size(); i++){
        for(int j = 1; j <= B.size(); j++){
            
            if(A[i-1] == B[])
        }
    }
}

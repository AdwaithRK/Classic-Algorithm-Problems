#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 3; 
    int m = 3; 


    vector<vector<int>> adj = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 0}
    };


    vector<vector<int>> map(m, vector<int>(m, 0));

    vector<int>ans(m);


    for(int i = 0; i < m; i++){
        for(int j=0;j<n;j++)
        {
            int flag=0;
            for(int k=0;k<m;k++)
            {
                if(adj[j][k]==i) flag=1;
                if(flag)
                {
                    map[i][adj[j][k]]++;
                }

            }
        }
        int pos=0;
        for(int j=0;j<m;j++)
        {
            
            if(j==i) continue;
            
            int cnt= map[i][j];
            if(cnt>(n/2)) pos++;
            if(cnt== (n/2) && i<j) pos++;
        }
        //
        ans[n-1-pos] = i;
    }


    for(auto k : ans) cout << k << "\n";


    return 0;
}
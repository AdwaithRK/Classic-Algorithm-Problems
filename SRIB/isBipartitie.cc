#include<bits/stdc++.h>


using namespace std;

bool isBipartite(vector<vector<int>> &adj, vector<int> &color, int start){
    
    queue<int> Q;

    Q.push(start);


    while(!Q.empty()){

        int node = Q.front();
        Q.pop();

        int now_color = color[node];

        for(auto ele : adj[node]){
            
            if(color[ele] == -1){
                color[ele] = !now_color;
                Q.push(ele);
            }
            else if(color[ele] == now_color){
                return false;
            }

        }
    }

    return true;
}





int main(int argc, const char** argv) {
    

    int n; // size of graph;


    vector<int> color(n, -1);// color
}
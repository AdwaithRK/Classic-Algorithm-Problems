#include<bits/stdc++.h>
using namespace std;


class Solution {

    int findSet(int i, vector<int> &parent){
        if(i == parent[i]) return i;

        return parent[i] = findSet(parent[i], parent);
    }


    void unionSet(int i, int j, vector<int> &rank, vector<int> &parent){

        int iSet = findSet(i, parent);
        int jSet = findSet(j, parent);

        if(iSet == jSet) return;


        if(rank[iSet] > rank[jSet]) parent[jSet] = iSet;

        else if(rank[iSet] < rank[jSet]) parent[iSet] = jSet;

        else{
            parent[jSet] = iSet;
            rank[iSet] = rank[iSet] + 1;
        } 
    }


public:
    int removeStones(vector<vector<int>>& stones) {
        
        int maxRows = 0;
        int maxCols = 0;
        //vector<int> rank();
       // vector<int> parent;

        for(int i = 0; i < stones.size(); i++){
            maxRows = max(stones[i][0], maxRows);
            maxCols = max(stones[i][1], maxCols);
        }

        vector<int> parent(maxRows + maxCols + 1);

        for(int i = 0; i < maxRows + maxCols + 1; i++) parent[i] = i;

        vector<int> ranks(maxRows + maxCols + 1, 0);


        for(auto stone : stones){
            unionSet(stone[0], stone[1] + maxRows + 1, ranks, parent);
        }

       int count = 0;

        for(int i = 0; i < parent.size(); i++){
            if(parent[i] == i) count++;
        }

        cout << "\n Count : " << count <<"\n";
    
    
        return 0;
    }
};


int main(){

    Solution a;

    vector<vector<int>> B = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    
    a.removeStones(B);

    return 0;
}
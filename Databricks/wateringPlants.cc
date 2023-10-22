#include<bits/stdc++.h>


using namespace std;

int solution(int n, int C, vector<int> plants){

    int ans = 0;
    int water_available = C;
    int steps = 1;


    for(int i = 0; i < plants.size(); i++){

        if(water_available < plants[i]){
            steps += 2*i;
            water_available = C - (plants[i] - water_available);
        }
        else{
            water_available = water_available - plants[i];
            steps++;
        }

    }

    return steps;
}



int main(){

}
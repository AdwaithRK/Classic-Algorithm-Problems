#include<bits/stdc++.h>
using namespace std;
vector<int> special_cities(int N, int X, int Y){

    int x = min(X, Y);

    int y = max(X, Y);


    map<int, int> distance_count;


    for(int i = 0; i < N; i++){

        for(int j = i + 1; j < N; i++){

            
            if( (i <= x && j <= x) || (i >= y && j >= y)){
                distance_count[j - i]++;
            }

            if( (i <= x && ( j > x && j <= y)) || ((i > x && i <= y)) &&  (j >= y) ){

                if( (j - i) > (abs(x - i) + abs(y - j) + 1) ){
                    distance_count[abs(x - i) +  abs(y - j) + 1]++;
                }
                else
                {
                    distance_count[j - i]++;
                }
            }

            // here do shit to find distance i, j use a map to count distance
        }
    }


    for(auto k : distance_count){
        cout << k.first << " : " << k.second;
    }

    return {};
}

int main(){
    
}
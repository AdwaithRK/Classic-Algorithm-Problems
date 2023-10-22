

#include<bits/stdc++.h>
using namespace std; 


unordered_map<int, int> value_index;


int find_stable_segment(){


        vector<int> capacity = {9, 3,3,3, 9};

        vector<int> prefix_sum = capacity;

        for(int i=1;i<5;i++)
        {
            prefix_sum[i]+=prefix_sum[i-1];
        }

        for(int i = 0; i < capacity.size(); i++){

            if(value_index.find(capacity[i]) != value_index.end()){
                if( 
                    i - value_index[capacity[i]] > 1
                ){
                    prefix_sum[i - 1] - prefix_sum[capacity[i] + 1]
                }
                else{
                    
                }
            }

        }

}
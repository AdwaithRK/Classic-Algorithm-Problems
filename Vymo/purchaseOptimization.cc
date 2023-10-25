#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> prefix_sums, int left, int right, int query_amount, int prev_sum){

    int start = left;
    
    while(left <= right){

        int mid = left + (right - left)/2;

        if((prefix_sums[mid] - prev_sum) <= query_amount){
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return (right - start + 1);
}



int main(){
    vector<int> prices = {3, 4, 5, 5, 7};


    int sum = prices[0];
    vector<int> prefix_sums = {sum};

    for(int i = 1; i < prices.size(); i++){
        sum += prices[i];
        prefix_sums.push_back(sum);
    }


    vector<vector<int>> queries = {
        {2, 10},
        {1, 24},
        {5, 5},
    };

    for(int i = 0; i < queries.size(); i++){
        int ans = binarySearch(prefix_sums, queries[i][0] - 1, prices.size() - 1, queries[i][1], prefix_sums[queries[i][0]-2]);
        cout << "answer : " << ans << "\n";
    }

    return 0;
}
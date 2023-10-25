#include<bits/stdc++.h>

using namespace std;

bool isFeasible(vector<int> array, int mid, int k){

    int pos = array[0];
    int ele_count = 0;


    for(int i = 0; i < array.size(); i++){
        if(array[i] - pos >= mid){

            pos = i;

            ele_count++;
            if(ele_count == k) return true;
        }
    }

    return false;
}



int binarySearch(vector<int> array, int k){

    int left = 1;
    int right = array[array.size() - 1];
    int ans = 0;


    while(left <= right){
        int mid = left + (right - left)/2;

        if(isFeasible(array, mid, k)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return right;
}








int main(){
    int n = 5;
    int k = 3;

    vector<int> array = {1, 4, 2, 8, 9};

    int ans = binarySearch(array, k);

    cout << "answer : " << ans << "\n";

    return 0;
}
#include<bits/stdc++.h>

using namespace std;



vector<int> sideElements(vector<int> fullBinaryTree){

    int i = 0;
    vector<int> ans;
    
    while(i < fullBinaryTree.size()){
        ans.push_back(fullBinaryTree[i]);

        i = 2*i + 1;
    }

    return ans;
}


int main(int argc, const char** argv) {

    vector<int> ans = {1,2,3,4,5,6,7,8,9};
    
    vector<int> temp = sideElements(ans);

    for(auto k : temp) cout << k << "\t";

    cout << "\n";

    return 0;
}

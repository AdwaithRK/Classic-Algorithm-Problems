#include <bits/stdc++.h>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>()> minHeap;

vector<int> find_median(int ele, vector<int> &ans){

    if(maxHeap.size() == 0 || ele <= maxHeap.top()){
        maxHeap.push(ele);
    }
    else
    {
        minHeap.push(ele);
    }

    if(minHeap.size() + 1 < maxHeap.size()){
        int temp = maxHeap.top();
        maxHeap.pop();
        minHeap.push(temp);
    }

    if(maxHeap.size() < minHeap.size()){
        int temp = minHeap.top();
        minHeap.pop();
        maxHeap.push(temp);
    }


    if(maxHeap.size() == minHeap.size())
        ans.push_back( (maxHeap.top() + minHeap.top())/2 );
    else
        ans.push_back(maxHeap.top());
}


int main()
{
}

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        priority_queue<pair<double, int>> pq; // value , index
        
        for(int i = 0; i < n; i++){
            double cost_per_kg = (arr[i].value/arr[i].weight);
            pair<double, int> temp = {cost_per_kg, i};
            pq.push(temp);
        }
        
        double value = 0;
        
        while(W > 0){
            pair<double, int> temp = pq.top();
            
            if(arr[temp.second].weight <= W){
                
                value += arr[temp.second].value;
                W = W - arr[temp.second].weight;
            }else{
                value += temp.first * W;
                W = 0;
            }
            
            pq.pop();
        }
        
        return value;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Endsn
#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> wins, vector<int> draws, vector<int> scored, vector<int> conceded){

    priority_queue<vector<int>> pq; // [score, goal_difference, index]

    for(int i = 0; i < wins.size(); i++){
        
        int score = wins[i] * 3 + draws[i] * 1;

        int goal_difference = scored[i] - conceded[i];

        pq.push({score, goal_difference, i});

    }
    

    vector<int> first = pq.top();
    pq.pop();

    vector<int> second = pq.top();
    pq.pop();


    return {first[2], second[2]};
}



int main(){

    vector<int> wins = {2, 1, 0};
    vector<int> draws = {1, 5, 6};
    vector<int> scored = {20, 15, 10};
    vector<int> conceded = {20, 10, 15};


    vector<int> ans = solution(wins, draws, scored, conceded);

    cout << "first : " << ans[0] << "\n";

    cout << "second : " << ans[1] << "\n";


    return 0;

}
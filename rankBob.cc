#include <bits/stdc++.h>

using namespace std;

vector<int> findRank(vector<int> score, vector<int> bobScores)
{

    vector<int> ans;

    for (int i = 0; i < bobScores.size(); i++)
    {

        int rank = 1;
        for (int j = 0; j < score.size(); j++)
        {

            if (j > 0 && score[j] < score[j - 1])
                rank++;

            if (bobScores[i] >= score[j])
            {

                if (ans.size() > 0)
                {
                    int min = ans[ans.size() - 1] < rank ? ans[ans.size() - 1] : rank;
                    ans.push_back(min);
                }
                else
                    ans.push_back(rank);
                break;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> score = {95, 90, 85, 60, 60, 55, 50};

    vector<int> bobScore = {55, 100, 80};

    vector<int> rankArray = findRank(score, bobScore);

    for (auto k : rankArray)
        cout << k << "\t";
    cout << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<string> missingRanges(vector<int> ranges, int low, int high)
{
    sort(ranges.begin(), ranges.end());

    vector<string> answer = {};
    int curIndex = 0;
    vector<int> temp = {};

    for (int i = low; i <= high; i++)
    {
        if (i == ranges[curIndex])
        {
            if (temp.size() > 0)
            {
                temp.push_back(i - 1);
                if (temp[0] == temp[1])
                {
                    answer.push_back(to_string(temp[0]));
                }
                else
                {
                    answer.push_back(to_string(temp[0]) + "->" + to_string(temp[1]));
                }
            }
            temp = {};
            curIndex++;
        }
        else
        {
            if (temp.size() == 0)
            {
                temp.push_back(i);
            }
        }
    }

    if (temp.size() > 0)
    {
        temp.push_back(high);
        if (temp[0] == temp[1])
        {
            answer.push_back(to_string(temp[0]));
        }
        else
        {
            answer.push_back(to_string(temp[0]) + "->" + to_string(temp[1]));
        }
    }

    return answer;
}

int main()
{
    vector<int> number = {4, 2, 45, 23, 70};
    int low = 1;
    int high = 75;

    vector<string> ans = missingRanges(number, low, high);

    for (auto answer : ans)
        cout << answer << "\n";

    return 0;
}
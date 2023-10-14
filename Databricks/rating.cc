#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> diffs)
{

    int min_rating = 1500;
    int max_rating = 1500;
    int base = 1500;

    for (int i = 0; i < diffs.size(); i++)
    {

        if (base + diffs[i] < min_rating){
            min_rating = base + diffs[i];
            base = min_rating;
        }

        if (base + diffs[i] > max_rating){
            max_rating = base + diffs[i];
            base = max_rating;
        }
    }

    return {min_rating, max_rating};
}

int main()
{

    vector<int> diffs = {100, -200, 350, 100, -600};

    vector<int> ans = solution(diffs);

    cout << "min : " << ans[0] << "\n";

    cout << "max : " << ans[1] << "\n";

    return 0;
}
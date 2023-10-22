#include <bits/stdc++.h>

using namespace std;

int countBitFlips(vector<int> numbers)
{

    int total_flips = 0;
    int n = numbers.size();

    for (int i = 0; i < 32; i++)
    {

        int one_count = 0;
        for (int k = 0; k < numbers.size(); k++)
        {
            if ((1 << i) & numbers[k])
                one_count++;
        }

        total_flips += min(one_count, (n - one_count));
    }

    return total_flips;
}

int main()
{

    vector<int> b = {1, };

    cout << countBitFlips(b) << "\n";

    return 0;
}
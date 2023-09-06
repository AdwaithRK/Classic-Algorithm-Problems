#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A = "fabcdei";
    string B = "kabceikkkkk";

    vector<vector<int>> DP(A.size() + 1, vector<int>(B.size() + 1, -1));

    for (int i = 0; i <= A.size(); i++)
    {
        for (int j = 0; j <= B.size(); j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
        }
    }

    for (int i = 1; i <= A.size(); i++)
    {
        for (int j = 1; j <= B.size(); j++)
        {

            if (A[i - 1] == B[i - 1])
            {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    int lcs_distance = DP[A.size()][B.size()];

    cout << "Lenght of longest common super sequence : " << A.size() + B.size() - lcs_distance << "\n\n";

    string super_sequence = "";

    int i = A.size(), j = B.size();

    while (i > 0 && j > 0)
    {

        if (A[i - 1] == B[j - 1])
        {
            super_sequence += A[i - 1];
            i--;
            j--;
        }
        else
        {
            if (DP[i - 1][j] > DP[i][j - 1])
            {
                super_sequence += A[i - 1];
                i--;
            }
            else
            {
                super_sequence += B[j - 1];
                j--;
            }
        }
    }

    while (i > 0)
    {
        super_sequence += A[i - 1];
        i--;
    }

    while (j > 0)
    {
        super_sequence += B[j - 1];
        j--;
    }

    reverse(super_sequence.begin(), super_sequence.end());

    cout << "Super sequence : " << super_sequence << "\n\n";

    return 0;
}

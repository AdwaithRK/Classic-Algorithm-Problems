#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A = "abcdefg";
    string B = "abcghiabcde";

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

            if (A[i - 1] == B[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    int i = A.size();
    int j = B.size();
    string temp = "";

    while (i > 0 && j > 0)
    {

        if (A[i - 1] == B[j - 1])
        {
            temp += A[i - 1];
            i--;
            j--;
        }
        else
        {
            if (DP[i - 1][j] > DP[i][j - 1])
            {
                i = i - 1;
            }
            else
            {
                j = j - 1;
            }
        }
    }

    reverse(temp.begin(), temp.end());

    cout << "Answer : " << DP[A.size()][B.size()] << "\n\n";

    cout << "String : " << temp << "\n\n";

    return 0;
}

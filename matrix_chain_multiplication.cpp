#include <bits/stdc++.h>
using namespace std;

int matrix_chain_multiplication(int i, int j, vector<int> array, vector<vector<int>> &DP)
{

    if (i >= j)
        return 0;

    int minAns = INT_MAX;

    if(DP[i][j] != -1) return DP[i][j];

    for (int k = i; k < j; k++)
    {
        int temp = matrix_chain_multiplication(i, k, array, DP) + matrix_chain_multiplication(k + 1, j, array, DP) + array[i - 1] * array[k] * array[j];

        minAns = min(temp, minAns);
    }

    DP[i][j] = minAns;

    return minAns;
}

int main(int argc, const char **argv)
{

    vector<int> resultArray = {40, 20, 30, 10, 30};

    vector<vector<int>> DP(resultArray.size(), vector<int>(resultArray.size(), -1));

    cout << "result Array : " << matrix_chain_multiplication(1, 4, resultArray, DP) << "\n";

    return 0;
}

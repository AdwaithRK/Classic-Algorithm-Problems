#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Memoize(4, vector<int>(51, -1));

int knapSack(vector<int> W, vector<int> V, int weight, int index)
{
    if (index >= W.size())
        return 0;
    if (Memoize[index][weight] != -1)
    {
        return Memoize[index][weight];
    }
    if (weight < W[index])
    {
        Memoize[index][weight] = knapSack(W, V, weight, index + 1);
        return Memoize[index][weight];
    }

    Memoize[index][weight] = max(V[index] + knapSack(W, V, weight - W[index], index + 1), knapSack(W, V, weight, index + 1));

    return Memoize[index][weight];
}

int main()
{
    vector<int> V = {60, 100, 120};
    vector<int> W = {10, 20, 30};

    int result = knapSack(W, V, 50, 0);

    cout << "\n Result is " << result << " \n";
}
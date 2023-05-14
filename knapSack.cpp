#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
vector<int> Memoize;

int knapSack(vector<int> W, vector<int> V, int weight, int index)
{
    // cout << "W size is " << W.size() << " and Index is " << index << " W[index] is " << W[index] << "\n";
    if (index >= W.size())
        return 0;
    if (Memoize[index] != -1)
    {
        cout << "memoization hit : " << Memoize[index] << " at index: " << index << "\n";
        return Memoize[index];
    }
    if (weight < W[index])
    {
        Memoize[index] = knapSack(W, V, weight, index + 1);
        cout << "memoization at " << index << " is " << Memoize[index] << "\n";
        return Memoize[index];
    }

    Memoize[index] = max(V[index] + knapSack(W, V, weight - W[index], index + 1), knapSack(W, V, weight, index + 1));
    cout << "memoization at " << index << " is " << Memoize[index] << "\n";

    return Memoize[index];
}

int main()
{
    vector<int> V = {60, 100, 120};
    vector<int> W = {10, 20, 30};
    Memoize.resize(V.size(), -1);

    int result = knapSack(W, V, 50, 0);

    cout << "\n Result is " << result << " \n";
}
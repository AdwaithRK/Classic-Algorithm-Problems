#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> final_permutation;

void get_permutation(vector<int> number, vector<bool> &isVisited, vector<int> result)
{
    if (result.size() == number.size())
    {
        final_permutation.push_back(result);

        return;
    }

    for (int i = 0; i < number.size(); i++)
    {
        if (!isVisited[i])
        {
            isVisited[i] = true;
            result.push_back(number[i]);
            get_permutation(number, isVisited, result);
            result.pop_back();
            isVisited[i] = false;
        }
    }

    return;
}

void nextPermutation(vector<int> &arr)
{
    int n = arr.size(), i, j;

    // Find for the pivot element.
    // A pivot is the first element from
    // end of sequenc ewhich doesn't follow
    // property of non-increasing suffix
    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            break;
        }
    }

    // Check if pivot is not found
    if (i < 0)
    {
        reverse(arr.begin(), arr.end());
    }

    // if pivot is found
    else
    {

        // Find for the successor of pivot in suffix
        for (j = n - 1; j > i; j--)
        {
            if (arr[j] > arr[i])
            {
                break;
            }
        }

        // Swap the pivot and successor
        swap(arr[i], arr[j]);

        // Minimise the suffix part
        reverse(arr.begin() + i + 1, arr.end());
    }
}

int main()
{
    vector<int> number = {1, 2, 3, 5, 4, 6, 7};

    //  sort(number.begin(), number.end());

    // vector<bool> isVisited(number.size(), false);

    //   get_permutation(number, isVisited, {});

    nextPermutation(number);

    for (auto a : number)
        cout << a << "\t";

    return 0;
}
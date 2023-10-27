#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> array = {3, 1, 7, 4};

    int n = array.size();
    int k = 6, count = 0;

    vector<int> max_from_left(array.size(), 0);
    vector<int> min_from_right(array.size(), 0);

    max_from_left[0] = array[0];
    for (int i = 1; i < array.size(); i++)
    {
        max_from_left[i] = max(array[i], max_from_left[i - 1]);
    }

    min_from_right[array.size() - 1] = array.back();

    for (int i = array.size() - 2; i >= 0; i--)
    {
        min_from_right[i] = min(array[i], min_from_right[i + 1]);
    }

    for (int i = 0; i < array.size() - 1; i++)
    {
        if (max_from_left[i] + min_from_right[i + 1] >= k)
            count++;
    }

    cout << "Count : " << count << "\n";

    return 0;
}
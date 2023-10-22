#include <bits/stdc++.h>

using namespace std;

int arrayRotationToSort(vector<int> array)
{
    int size = array.size();
    vector<int> sored_array = array;
    vector<int> new_array;
    int count = 0;
    while (count < size)
    {
        for (int i = 0; i < (size / 2); i++)
        {
            new_array.push_back(array[i]);
            new_array.push_back(array[(size / 2) + i]);
        }

        for (auto k : new_array)
            cout << k << "\t";
        cout << "\n";

        count++;

        if (new_array == sored_array)
            break;
        else
        {
            array = new_array;
            new_array = {};
        }
    }

    return count;
}

int arrayRotationCount2(vector<int> array)
{
    int size = array.size();

    int idx = 1;

    int count = 0;

    do
    {
        idx = (2 * idx) % (size - 1);
        count++;

    } while (idx != 1);

    return count;
}

int main()
{

    int k = 20;

    vector<int> array;

    for (int i = 1; i <= k; i++)
        array.push_back(i);

    int ans = arrayRotationToSort(array);

    cout << "rotation count 1: " << ans << "\n";


    int ans1 = arrayRotationCount2(array);

    cout << "rotation count 2: " << ans1 << "\n";

    return 0;
}
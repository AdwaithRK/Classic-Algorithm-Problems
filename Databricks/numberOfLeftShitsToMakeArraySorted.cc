#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array)
{

    int start = 0;
    int end = array.size() - 1;

    while (start < end)
    {

        int mid = start + (end - start) / 2;

        if (array[mid] > array[mid + 1] && array[mid] > array[mid - 1])
        {
            return mid;
        }

        if()

        if (array[start] <= array[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return -1;
}

int main()
{
    vector<int> k = {6, 1, 2, 3, 4};

    int a = solution(k);

    cout << a + 1 << "\n";

    return 0;
}
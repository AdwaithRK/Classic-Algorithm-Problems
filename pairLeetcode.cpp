#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({nums1[0] + nums2[0], 0, 0});

        vector<vector<int>> result;
        int row1 = 0;
        int row2 = 0;

        while (result.size() < k && pq.size() > 0)
        {

            vector<int> temp = pq.top();
            pq.pop();

            row1 = temp[1];
            row2 = temp[2];

            result.push_back({row1, row2});

            if (row1 + 1 < nums1.size()){
                cout << "row1 : " << row1 + 1 << " row2 : " << row2 << "\n";
                pq.push({nums1[row1 + 1] + nums2[row2], row1 + 1, row2});
            }

            if (row2 + 1 < nums2.size()){
                cout << "row1 : " << row1 << " row2 : " << row2 + 1 << "\n";
                pq.push({nums1[row1] + nums2[row2 + 1], row1, row2 + 1});
            }
        }

        return result;
    }
};

int main()
{

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3};
    int k = 3;

    Solution a;

    vector<vector<int>> m = a.kSmallestPairs(nums1, nums2, k);

    return 0;
}
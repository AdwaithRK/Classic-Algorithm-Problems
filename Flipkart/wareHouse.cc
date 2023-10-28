#include <bits/stdc++.h>

using namespace std;

int wareHouse(string str, int k)
{

    vector<int> vowel_count(str.size(), 0);

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u')
        {
            if (i == 0)
                vowel_count[i] = 1;
            else
            {
                vowel_count[i] = 1 + vowel_count[i - 1];
            }
        }
        else
        {
            if (i == 0)
                vowel_count[i] = 0;
            else
            {
                vowel_count[i] = vowel_count[i - 1];
            }
        }
    }

    int segment_start = 0;

    int max_vowel_count_in_segment = 0, max_start = 0, max_end = 0;

    while (segment_start < str.size())
    {
        int segment_end = segment_start + (k - 1);
        int prev_vowel_count = 0;

        if (segment_start == 0)
        {
            prev_vowel_count = 0;
        }
        else
        {
            prev_vowel_count = vowel_count[segment_start - 1];
        }

        if (segment_end >= str.size())
            segment_end = str.size() - 1;

        int segment_vowel_count = vowel_count[segment_end] - prev_vowel_count;

        if (max_vowel_count_in_segment < segment_vowel_count)
        {
            max_vowel_count_in_segment = segment_vowel_count;
        }

        segment_start = segment_end + 1;
    }

    return max_vowel_count_in_segment;
}

int main()
{
    string k = "kbeuyueiiiio";
    int n = 3;

    int ans = wareHouse(k, n);

    cout << "answer : " << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A = "adwaith";
    string B = "wax";

    int string_two_index = 0;

    for (int string_one_index = 0; string_one_index < A.size(); string_one_index++)
    {
        if(A[string_one_index] == B[string_two_index]){
            string_two_index++;
        }
        else
        {
            string_two_index = 0;
        }

        if(string_two_index == B.size()) break;
    }

    if (string_two_index == B.size()) cout << "yes\n";
    else cout << "No\n";

    return 0;
}
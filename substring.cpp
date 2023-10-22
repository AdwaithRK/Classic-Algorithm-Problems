using namespace std;

#include <iostream>
#include <bits/stdc++.h>

string LongestPalindromicSubstring(string s)
{
    // Replace this placeholder return statement with your code

    int max_lenght = 0, lenght = 1;
    string ans = "";

    for(int i = 0; i < s.size(); i++){

        for(int j = 0; j < s.size(); j++){

            if( i + j < s.size() && i - j >= 0){

                if(s[i + j] == s[i - j]){
                
                    if(max_lenght < (i + j) - (i - j) + 1){
                        max_lenght = (i + j) - (i - j) + 1;
                        ans = s.substr(i - j, max_lenght);
                    }

                } else break;
            }

        }
    }

    for(int i = 0; i < s.size(); i++){

        for(int j = 0; j < s.size(); j++){

            if( i + j + 1 < s.size() && i - j >= 0){

                if(s[i + j + 1] == s[i - j]){
                
                    if(max_lenght < (i + j + 1) - (i - j) + 1){
                        max_lenght = (i + j + 1) - (i - j) + 1;
                        ans = s.substr(i - j, max_lenght);
                    }
                } else break;
            }

        }
    }



    return ans;
}


int main(){

    string temp = "aabbccddccbbae";

    string ans = LongestPalindromicSubstring(temp);

    cout << "Answer : " << ans << " \n";


    return 0;

}
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    bool isEndOfWord;
    map<char, TrieNode *> alphabets;
    int number;
};

TrieNode *getNode()
{
    TrieNode *ele = new TrieNode();
    ele->isEndOfWord = false;

    return ele;
}

void insert(string number, TrieNode *root)
{

    TrieNode *pCrawler = root;

    for (int i = 0; i < number.size(); i++)
    {

        if (pCrawler->alphabets[number[i]] == NULL)
        {
            pCrawler->alphabets[number[i]] = getNode();
        }

        // cout << "i : " << i << "\n";
        pCrawler = pCrawler->alphabets[number[i]];
    }

    pCrawler->number = stoi(number);

    // cout << "inserted number : " << pCrawler -> number << "\n";

    pCrawler->isEndOfWord = true;
}

void DFS(TrieNode *root, vector<int> result)
{

    if (root->isEndOfWord)
    {
        result.push_back(root->number);
    }

    if (root->alphabets.size() == 0)
    {
        return;
    }

    for (auto ele : root->alphabets)
    {
        DFS(ele.second, result);
    }
}

class Solution
{
    TrieNode *root = NULL;

public:
    vector<int> lexicalOrder(int n)
    {

        root = getNode();

        for (int i = 1; i <= n; i++)
        {
            string temp = to_string(i);
            insert(temp, root);
        }

        vector<int> ans = {};

        DFS(root, ans);

        return ans;
    }
};

int main()
{
    Solution k;

    vector<int> s = k.lexicalOrder(13);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << "\t";
    }

    cout << "\n";

    return 1;
}
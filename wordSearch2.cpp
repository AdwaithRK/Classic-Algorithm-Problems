#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> alphabets;
    bool isEndOfWord;
};

TrieNode *getNode()
{
    TrieNode *temp = new TrieNode();

    temp->isEndOfWord = false;

    return temp;
}

void insertWord(TrieNode *root, string word)
{

    TrieNode *pCrawler = root;

    for (int i = 0; i < word.size(); i++)
    {
        if (pCrawler->alphabets[word[i]] == NULL)
        {
            pCrawler->alphabets[word[i]] = getNode();
        }

        pCrawler = pCrawler->alphabets[word[i]];
    }

    pCrawler->isEndOfWord = true;
}

bool searchWord(TrieNode *root, string word)
{
    TrieNode *pCrawler = root;

    for (int i = 0; i < word.size(); i++)
    {
        if (pCrawler->alphabets[word[i]] == NULL)
            return false;

        pCrawler = pCrawler->alphabets[word[i]];
    }

    return pCrawler->isEndOfWord;
}

class Solution
{

    TrieNode *root;

    void backTracking(int row, int col, TrieNode *root, vector<vector<char>> &board, string word)
    {

        if (row < 0 || col < 0)
            return;

        if (row >= board.size() || row >= board[0].size())
            return;

        insertWord(root, word + board[row][col]);

        backTracking(row + 1, col, root, board, word + board[row][col]);
        backTracking(row, col + 1, root, board, word + board[row][col]);
        backTracking(row, col + 1, root, board, word + board[row][col]);
        backTracking(row, col + 1, root, board, word + board[row][col]);
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        root = getNode();

        string word = "";
        backTracking(0, 0, root, board, word);

        return {"adwaith"};
    }
};

int main(int argc, const char **argv)
{

    Solution A;

    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};

    A.findWords(board, words);

    return 0;
}
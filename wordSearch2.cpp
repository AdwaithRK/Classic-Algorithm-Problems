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

bool isPrefix(TrieNode *root, string word)
{
    TrieNode *pCrawler = root;

    for (int i = 0; i < word.size(); i++)
    {
        if (pCrawler->alphabets[word[i]] == NULL)
            return false;

        pCrawler = pCrawler->alphabets[word[i]];
    }

    return true;
}

class Solution
{

    TrieNode *root;
    vector<string> result;

    void backTracking(int row, int col, TrieNode *root, vector<vector<char>> &board, string word, vector<vector<bool>> visited_board)
    {

        // cout << "row : " << row << " col :" << col << "\n\n";

        if (row < 0 || col < 0)
            return;

        if (row >= board.size() || col >= board[0].size())
            return;

        if (visited_board[row][col])
            return;

        if (!isPrefix(root, word + board[row][col])) return; 

        if(searchWord(root, word + board[row][col]))result.push_back(word + board[row][col]);

        visited_board[row][col] = true;
        backTracking(row + 1, col, root, board, word + board[row][col], visited_board);
        backTracking(row - 1, col, root, board, word + board[row][col], visited_board);
        backTracking(row, col + 1, root, board, word + board[row][col], visited_board);
        backTracking(row, col - 1, root, board, word + board[row][col], visited_board);
        visited_board[row][col] = false;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        root = getNode();


        string word = "";


        for (int i = 0; i < words.size(); i++)
        {
            insertWord(root, words[i]);
        }



        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                vector<vector<bool>> visited_board(board.size(), vector<bool>(board[0].size(), false));
                backTracking(i, j, root, board, word, visited_board);
            }
        }

        return result;
    }
};

int main(int argc, const char **argv)
{

    Solution A;

    // vector<string> result;

    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};

    vector<string> result = A.findWords(board, words);

    for (auto k : result)
        cout << k << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool checkBackTrack(int row, int col, vector<vector<char>> &board, string word, vector<vector<bool>> &visited)
    {

        if (word.size() == 0)
            return true;

        if (row >= board.size())
            return false;
        if (col >= board[0].size())
            return false;
        if (row < 0 || col < 0)
            return false;

        bool ans = false;

        cout << "word size : " << word.size() << " now checking for : " << word[0] << " with : " << board[row][col] << " \n";

        if (board[row][col] == word[0] && !visited[row][col])
        {

            cout << "visiting : " << board[row][col] << " row : " << row << " col : " << col << "\n";

            visited[row][col] = true;
            ans = checkBackTrack(row + 1, col, board, word.substr(1), visited) || checkBackTrack(row, col + 1, board, word.substr(1), visited) || checkBackTrack(row - 1, col, board, word.substr(1), visited) || checkBackTrack(row, col - 1, board, word.substr(1), visited);
            visited[row][col] = false;
        }
        return ans;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {

        bool result = false;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                bool temp = checkBackTrack(i, j, board, word, visited);
                result = temp || result;
                if (result)
                    return true;
            }
        }

        return result;
    }
};

int main()
{

    Solution a;

    vector<vector<char>> arrayL = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};

    cout << a.exist(arrayL, "ABCESEEEFS");

    return 0;
}
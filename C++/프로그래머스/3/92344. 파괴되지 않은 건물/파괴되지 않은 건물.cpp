#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    vector<vector<int>> Table(board.size(), vector<int>(board[0].size()));
    for (const vector<int>& sk : skill)
    {
        int type = sk[0], r1 = sk[1], c1 = sk[2], r2 = sk[3], c2 = sk[4], degree = sk[5];
        if (type == 1)
        {
            Table[r1][c1] -= degree;
            if (r2 + 1 < board.size())
            {
                Table[r2 + 1][c1] += degree;
            }
            if (c2 + 1 < board[0].size())
            {
                Table[r1][c2 + 1] += degree;
            }
            if (r2 + 1 < board.size() && c2 + 1 < board[0].size())
            {
                Table[r2 + 1][c2 + 1] -= degree;
            }
        }
        else
        {
            Table[r1][c1] += degree;
            if (r2 + 1 < board.size())
            {
                Table[r2 + 1][c1] -= degree;
            }
            if (c2 + 1 < board[0].size())
            {
                Table[r1][c2 + 1] -= degree;
            }
            if (r2 + 1 < board.size() && c2 + 1 < board[0].size())
            {
                Table[r2 + 1][c2 + 1] += degree;
            }
        }
    }
    
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 1; j < board[i].size(); j++)
        {
            Table[i][j] += Table[i][j - 1];
        }
    }
    for (int j = 0; j < board[0].size(); j++)
    {
        for (int i = 1; i < board.size(); i++)
        {
            Table[i][j] += Table[i - 1][j];
        }
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            board[i][j] += Table[i][j];
        }
    }
    
    int answer = board.size() * board[0].size();
    for (const vector<int>& row : board)
    {
        for (int n : row)
        {
            if (n <= 0)
            {
                answer--;
            }
        }
    }
    return answer;
}
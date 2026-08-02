#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    vector<vector<int>> Table(board.size() + 1, vector<int>(board[0].size() + 1));
    for (const vector<int>& s : skill)
    {
        int type = s[0], r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], degree = s[5];
        if (type == 1)
        {
            degree *= -1;
        }
        
        Table[r1][c1] += degree;
        Table[r1][c2 + 1] -= degree;
        Table[r2 + 1][c1] -= degree;
        Table[r2 + 1][c2 + 1] += degree;        
    }
    
    for (int i = 1; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Table[i][j] += Table[i - 1][j];
        }
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 1; j < board[i].size(); j++)
        {
            Table[i][j] += Table[i][j - 1];
        }
    }
    
    int answer = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] + Table[i][j] > 0)
            {
                answer++;
            }
        }
    }
    return answer;
}
#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;    
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (i == 0 || j == 0)
            {
                answer = max(answer, board[i][j]);
                continue;
            }
            
            if (!board[i][j])
            {
                continue;
            }
            if (!board[i - 1][j] || !board[i][j - 1] || !board[i - 1][j - 1])
            {
                continue;
            }
            board[i][j] = min(board[i - 1][j], min(board[i][j - 1], board[i - 1][j - 1])) + 1;
            answer = max(answer, board[i][j]);
        }
    }
    
    return answer * answer;
}
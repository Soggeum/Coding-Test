#include <string>
#include <vector>

using namespace std;

int Try(int m, int n, vector<string>& board)
{
    vector<vector<bool>> Table(m, vector<bool>(n, false));
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (board[i][j] == '0')
            {
                continue;
            }
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1])
            {
                Table[i][j] = true;
                Table[i][j + 1] = true;
                Table[i + 1][j] = true;
                Table[i + 1][j + 1] = true;
            }
        }
    }
    
    int result = 0;
    for (int j = 0; j < n; j++)
    {
        int Target = m - 1;
        for (int i = m - 1; i >= 0; i--)
        {
            if (!Table[i][j])
            {
                board[Target][j] = board[i][j];
                Target--;
            }
            else
            {
                result++;
            }
        }
        for (; Target >= 0; Target--)
        {
            board[Target][j] = '0';
        }
    }
    
    return result;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (1)
    {
        int Score = Try(m, n, board);
        if (Score)
        {
            answer += Score;
        }
        else
        {
            return answer;
        }
    }
}
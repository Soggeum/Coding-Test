#include <string>
#include <vector>

using namespace std;

bool ShouldDelete(const vector<string>& board, vector<vector<bool>>& Same)
{
    bool bFlag = false;
    for (int i = 0; i < board.size() - 1; i++)
    {
        for (int j = 0; j < board[0].size() - 1; j++)
        {
            char c = board[i][j];
            if (isalpha(c))
            {
                if (c == board[i][j + 1] && c == board[i + 1][j] && c == board[i + 1][j + 1])
                {
                    bFlag = true;
                    Same[i][j] = true;
                    Same[i][j + 1] = true;
                    Same[i + 1][j] = true;
                    Same[i + 1][j + 1] = true;
                }                
            }
        }
    }
    
    return bFlag;
}

int solution(int m, int n, vector<string> board) {
    vector<vector<bool>> Same(m, vector<bool>(n));
    while (ShouldDelete(board, Same))
    {      
        for (int j = 0; j < n; j++)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                if (Same[i][j])
                {
                    for (int k = i; k > 0; k--)
                    {
                        board[k][j] = board[k - 1][j];
                        Same[k][j] = Same[k - 1][j];                        
                    }
                    board[0][j] = '0';
                    Same[0][j] = false;
                    i++;
                }
            }
        }
        
        Same = vector<vector<bool>>(m, vector<bool>(n));
    }
    
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isdigit(board[i][j]))
            {
                answer++;
            }
        }
    }
    return answer;
}
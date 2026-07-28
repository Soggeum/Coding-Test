#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    bool bFlag = true;
    while (bFlag)
    {
        bFlag = false;
        vector<vector<bool>> Delete(m, vector<bool>(n));
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                char c = board[i][j];
                if (c == '0')
                {
                    continue;
                }
                if (board[i][j + 1] == c && board[i + 1][j] == c && board[i + 1][j + 1] == c)
                {
                    bFlag = true;
                    Delete[i][j] = true;
                    Delete[i][j + 1] = true;
                    Delete[i + 1][j] = true;
                    Delete[i + 1][j + 1] = true;
                }
            }
        }
        
        for (int j = 0; j < n; j++)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                if (Delete[i][j])
                {
                    for (int k = i; k > 0; k--)
                    {
                        board[k][j] = board[k - 1][j];
                        Delete[k][j] = Delete[k - 1][j];
                    }
                    board[0][j] = '0';
                    Delete[0][j] = false;
                    i++;
                }
            }
        }
    }
    
    int answer = 0;
    for (const string& s : board)
    {
        for (char c : s)
        {
            if (c == '0')
            {
                answer++;
            }
        }
    }
    return answer;
}
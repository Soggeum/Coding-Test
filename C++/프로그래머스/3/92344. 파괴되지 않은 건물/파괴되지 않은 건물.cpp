#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int N = board.size(), M = board[0].size();
    vector<vector<int>> Table(N, vector<int>(M));
    for (const vector<int>& s : skill)
    {
        int type = s[0], r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], degree = s[5];
        if (type == 1)
        {
            degree *= -1;
        }
        
        Table[r1][c1] += degree;
        if (c2 + 1 < M)
        {
            Table[r1][c2 + 1] -= degree;
        }
        if (r2 + 1 < N)
        {
            Table[r2 + 1][c1] -= degree;
        }
        if (c2 + 1 < M && r2 + 1 < N)
        {
            Table[r2 + 1][c2 + 1] += degree;
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            Table[i][j] += Table[i][j - 1];
        }
    }
    for (int j = 0; j < M; j++)
    {
        for (int i = 1; i < N; i++)
        {
            Table[i][j] += Table[i - 1][j];
        }
    }
    
    int answer = board.size() * board[0].size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] + Table[i][j] <= 0)
            {
                answer--;
            }
        }
    }
    
    return answer;
}
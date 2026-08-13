#include <string>
#include <vector>

using namespace std;

struct Node
{
    char c;
    bool d;
};

int solution(int m, int n, vector<string> board) {
    vector<vector<Node>> Table(m, vector<Node>(n));
    for (int i = 0;i < m; i++)
    {
        for (int j = 0;j < n; j++)
        {
            Table[i][j].c = board[i][j];
            Table[i][j].d = false;
        }
    }
    
    bool bFlag = true;
    while (bFlag)
    {
        bFlag = false;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1;j < n; j++)
            {
                char c = Table[i][j].c;
                if (c && c == Table[i][j - 1].c && c == Table[i - 1][j - 1].c && c == Table[i - 1][j].c)
                {
                    bFlag = true;
                    Table[i][j].d = true;
                    Table[i][j - 1].d = true;
                    Table[i - 1][j].d = true;
                    Table[i - 1][j - 1].d = true;
                }
            }
        }
        
        for (int j = 0;j < n; j++)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                if (Table[i][j].d)
                {
                    for (int k = i; k > 0; k--)
                    {
                        Table[k][j] = Table[k - 1][j];
                    }
                    Table[0][j] = {0, false};
                    i++;
                }
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0;j < n; j++)
        {
            if (Table[i][j].c == 0)
            {
                answer++;
            }
        }
    }
    return answer;
}
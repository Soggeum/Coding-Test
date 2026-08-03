#include <string>
#include <vector>

using namespace std;

struct Node
{
    char c;
    bool flag;    
};

int solution(int m, int n, vector<string> board) {
    vector<vector<Node>> Table(m, vector<Node>(n));
    for (int i = 0; i < m ; i++)
    {
        for (int j = 0;j < n; j++)
        {
            Table[i][j].c = board[i][j];
        }
    }
    
    bool wflag = false;
    do {
        wflag = false;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0;j < n - 1; j++)
            {
                char c = Table[i][j].c;
                if (c && c == Table[i][j + 1].c && c == Table[i + 1][j].c && c== Table[i + 1][j + 1].c)
                {
                    Table[i][j].flag = true;
                    Table[i][j + 1].flag = true;
                    Table[i + 1][j].flag = true;
                    Table[i + 1][j + 1].flag = true;
                }
            }
        }
        
        for (int j= 0; j < n; j++)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                if (Table[i][j].flag)
                {
                    wflag = true;
                    for (int k = i; k > 0; k--)
                    {
                        Table[k][j] = Table[k - 1][j];
                    }
                    Table[0][j] = {0, false};
                    i++;
                }
            }
    }
    } while (wflag);
    
    
    int answer = 0;
    for (const vector<Node>& row : Table)
    {
        for (const Node& n : row)
        {
            if (n.c == 0)
            {
                answer++;
            }
        }
    }
    return answer;
}
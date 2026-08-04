#include <vector>

using namespace std;

struct Node
{
    int H, V;    
};

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<Node>> Table(m, vector<Node>(n));
    Table[0][0] = {1, 0};
    for (int j = 1; j < n; j++)
    {
        if (city_map[0][j] == 1)
        {
            break;
        }
        Table[0][j].H = 1;
    }
    for (int i = 1; i < m; i++)
    {
        if (city_map[i][0] == 1)
        {
            break;
        }
        Table[i][0].V = 1;
    }
    
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (city_map[i][j] == 1)
            {
                continue;
            }
            if (city_map[i - 1][j] != 2)
            {
                Table[i][j].V += Table[i - 1][j].H;
            }
            Table[i][j].V += Table[i - 1][j].V;
            
            if (city_map[i][j - 1] != 2)
            {
                Table[i][j].H += Table[i][j - 1].V;
            }
            Table[i][j].H += Table[i][j - 1].H;
            
            Table[i][j].V %= MOD;
            Table[i][j].H %= MOD;
        }
    }
    
    return (Table[m - 1][n - 1].H + Table[m - 1][n - 1].V) % MOD;
}
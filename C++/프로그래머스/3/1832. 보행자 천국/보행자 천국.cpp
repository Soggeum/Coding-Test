#include <vector>

using namespace std;

int MOD = 20170805;

struct Node
{
    int H, V;    
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    if (m * n == 1)
    {
        return 1;
    }
    vector<vector<Node>> Table(m, vector<Node>(n));
    for (int i = 0; i < m; i++)
    {
        if (city_map[i][0] == 1)
        {
            break;
        }
        Table[i][0].V = 1;
    }
    for (int j = 0; j < n; j++)
    {
        if (city_map[0][j] == 1)
        {
            break;
        }
        Table[0][j].H = 1;
    }
    
    for (int i = 1;i < m; i++){
        for (int j = 1; j < n; j++)
        {
            if (city_map[i][j] == 1)
            {
                continue;
            }
                
            if (city_map[i - 1][j] != 2)
            {
                Table[i][j].V = (Table[i][j].V + Table[i - 1][j].H) % MOD;    
            }
            Table[i][j].V = (Table[i][j].V + Table[i - 1][j].V) % MOD;
            if (city_map[i][j - 1] != 2)
            {
                Table[i][j].H = (Table[i][j].H + Table[i][j - 1].V) % MOD;    
            }
            Table[i][j].H = (Table[i][j].H + Table[i][j - 1].H) % MOD; 
        }
    }
    
    return (Table.back().back().H + Table.back().back().V) % MOD;
}
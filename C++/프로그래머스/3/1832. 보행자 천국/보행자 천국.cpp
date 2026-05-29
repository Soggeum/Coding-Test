#include <vector>

#include <iostream>

using namespace std;

int MOD = 20170805;

struct Node
{
    int FromUp, FromLeft;    
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<Node>> Table(m, vector<Node>(n));
    for (int i = 1; i < n; i++)
    {
        if (city_map[0][i] == 1)
        {
            break;
        }
        Table[0][i].FromLeft = 1;
    }    
    for (int i = 1; i < m; i++)
    {
        if (city_map[i][0] == 1)
        {
            break;
        }
        Table[i][0].FromUp = 1;
    }
    
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (city_map[i][j] != 1)
            {
                if (city_map[i - 1][j] == 2)
                {
                    Table[i][j].FromUp = Table[i - 1][j].FromUp % MOD;
                }
                else
                {
                    Table[i][j].FromUp = (Table[i - 1][j].FromUp + Table[i - 1][j].FromLeft) % MOD;
                }
                
                if (city_map[i][j - 1] == 2)
                {
                    Table[i][j].FromLeft = Table[i][j - 1].FromLeft % MOD;
                }
                else
                {
                    Table[i][j].FromLeft = (Table[i][j - 1].FromUp + Table[i][j - 1].FromLeft) % MOD;
                }
            }
        }
    }    
    
    return (Table[m - 1][n - 1].FromUp + Table[m - 1][n - 1].FromLeft) % MOD;
}
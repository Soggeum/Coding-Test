#include <string>
#include <vector>

using namespace std;

int solution(int N, int number) {
    vector<vector<int>> Table(9);
    for (int i = 1; i < 9; i++)
    {
        Table[i].push_back(stoi(string(i, N + '0')));
        if (Table[i][0] == number)
        {
            return i;
        }
    }
    
    for (int i = 2; i < 9; i++)
    {
        for (int j = 1; j < i; j++)
        {
            for (int op1 : Table[j])
            {
                for (int op2 : Table[i - j])
                {
                    int num = op1 + op2;
                    if (num == number)
                    {
                        return i;
                    }
                    Table[i].push_back(num);
                    
                    num = op1 - op2;
                    if (num == number)
                    {
                        return i;
                    }
                    Table[i].push_back(num);
                    
                    num = op1 * op2;
                    if (num == number)
                    {
                        return i;
                    }
                    Table[i].push_back(num);
                    
                    if (op2 != 0)
                    {
                        num = op1 / op2;
                        if (num == number)
                        {
                            return i;
                        }
                        Table[i].push_back(num);
                    }
                }
            }
        }
    }
    
    
    return -1;
}
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int>> Table(8 + 1);
    for (int i = 1; i < 9; i++)
    {
        Table[i].insert(stoi(string(i, '0' + N)));
        if (Table[i].find(number) != Table[i].end())
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
                    int Value = op1 + op2;
                    Table[i].insert(Value);
                    
                    Value = op1 - op2;
                    Table[i].insert(Value);
                    
                    Value = op1 * op2;
                    Table[i].insert(Value);
                    
                    if (op2 != 0)
                    {
                        Value = op1 / op2;
                        Table[i].insert(Value);
                    }
                }
            }
        }
        if (Table[i].find(number) != Table[i].end())
        {
            return i;
        }
    }
    
    return -1;
}
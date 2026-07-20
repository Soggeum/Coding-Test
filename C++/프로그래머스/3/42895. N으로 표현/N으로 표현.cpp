#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> DP(9);
    for (int i = 1; i <= 8; i++)
    {
        int Num = stoi(string(i, '0' + N));
        if (Num == number)
        {
            return i;
        }
        DP[i].insert(Num);
    }
    
    for (int i = 2; i <= 8; i++)
    {
        for (int j = 1; j < i; j++)
        {
            for (int op1 : DP[j])
            {
                for (int op2 : DP[i -j])
                {
                    int Num = op1 + op2;
                    if (Num == number)
                    {
                        return i;
                    }
                    DP[i].insert(Num);
                    
                    Num = op1 * op2;
                    if (Num == number)
                    {
                        return i;
                    }
                    DP[i].insert(Num);
                    
                    Num = op1 - op2;
                    if (Num == number)
                    {
                        return i;
                    }
                    DP[i].insert(Num);
                    
                    if (op2 != 0)
                    {
                        Num = op1 / op2;
                        if (Num == number)
                        {
                            return i;
                        }
                        DP[i].insert(Num);
                    }
                }
            }
        }
    }
    
    return -1;
}
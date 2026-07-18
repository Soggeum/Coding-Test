#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> DP(9);    
    for (int i = 1; i <= 8; i++)
    {
        int Base = stoi(string(i, '0' + N));
        if (Base == number)
        {
            return i;
        }
        DP[i].insert(Base);
        
        for (int j = 1; j < i; j++)
        {
            for (int op1 : DP[j])
            {
                for (int op2 : DP[i - j])
                {
                    int NewNumber = op1 + op2;
                    DP[i].insert(NewNumber);
                    if (NewNumber == number)
                    {
                        return i;
                    }
                    
                    NewNumber = op1 - op2;
                    DP[i].insert(NewNumber);
                    if (NewNumber == number)
                    {
                        return i;
                    }
                    
                    NewNumber = op1 * op2;
                    DP[i].insert(NewNumber);
                    if (NewNumber == number)
                    {
                        return i;
                    }
                    
                    if (op2 != 0)
                    {
                        NewNumber = op1 / op2;
                        DP[i].insert(NewNumber);
                        if (NewNumber == number)
                        {
                            return i;
                        }
                    }
                }
            }
        }
    }
    
    return -1;
}
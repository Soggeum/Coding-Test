#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    long long Start = 1, End = 1ll * n * 10000, Time = End;
    while (Start <= End)
    {
        long long Mid = (Start + End) / 2, Cnt = 0;
        for (int core : cores)
        {
            Cnt += Mid / core + 1;
        }
        
        if (Cnt >= n)
        {
            Time = Mid;
            End = Mid - 1;
        }
        else
        {
            Start = Mid + 1;
        }
    }
    
    for (int core : cores)
    {
        n -= (Time - 1) / core + 1;
    }
    
    for (int i = 0; i < cores.size(); i++)
    {
        if (Time % cores[i] == 0)
        {
            n--;
            if (n == 0)
            {
                return i + 1;
            }
        }
    }
    
    return -1;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    if (n <= cores.size())
    {
        return n;
    }
    
    long long Start = 1, End = n * 10000, Time = End;
    while (Start <= End)
    {
        long long Mid = (Start + End) / 2;
        long long Count = 0;
        for (int c : cores)
        {
            Count += Mid / c + 1;
        }
        
        if (Count >= n)
        {
            Time = Mid;
            End = Mid - 1;
        }
        else
        {
            Start = Mid + 1;
        }
    }
    
    int Cnt = 0;
    for (int i = 0; i < cores.size(); i++)
    {
        Cnt += (Time - 1) / cores[i] + 1;
    }
    for (int i = 0; i < cores.size(); i++)
    {
        if (Time % cores[i] == 0)
        {
            Cnt++;
        }
        if (Cnt == n)
        {
            return i + 1;
        }
    }
    return cores.size();
}
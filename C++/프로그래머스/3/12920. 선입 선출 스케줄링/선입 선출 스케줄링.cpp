#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    if (cores.size() >= n)
    {
        return n;
    }
    
    int Start = 1, End = 10000 * 50000, Time = End;
    while (Start <= End)
    {
        int Mid = (Start + End) / 2 ;
        long long Count = 0;
        for (int c : cores)
        {
            Count += 1 + Mid / c;
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
    
    int Count = cores.size();
    for (int i = 0; i < cores.size(); i++)
    {
        Count += (Time - 1) / cores[i];
    }
    for (int i = 0; i < cores.size(); i++)
    {
        if (Time % cores[i] == 0)
        {
            Count++;
            if (Count == n)
            {
                return i + 1;
            }
        }
    }
    return 1;
}
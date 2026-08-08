#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    long long Start = 1, End = n * 10000ll, answer = End;
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
            answer = Mid;
            End = Mid - 1;
        }
        else
        {
            Start  = Mid + 1;
        }
    }
    
    for (int c : cores)
    {
        n -= (answer - 1) / c + 1;        
    } 
    for (int i = 0; i < cores.size(); i++)
    {
        if (answer % cores[i] == 0)
        {
            n--;
        }
        if (n == 0)
        {
            return i + 1;
        }
    } 
    return cores.size();
}
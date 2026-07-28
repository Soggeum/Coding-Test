#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 1ll * n * 1000000000, Start = 0, End = 1ll * n * 1000000000;
    while (Start <= End)
    {
        long long Mid = (Start + End) / 2;
        long long Count = 0;
        for (int t : times)
        {
            Count += Mid / t;
        }
        
        if (Count >= n)
        {
            answer = min(answer, Mid);
            End = Mid - 1;
        }
        else
        {
            Start = Mid + 1;
        }
    }
    return answer;
}
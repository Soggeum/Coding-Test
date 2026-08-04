#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long Start = 1, End = 1ll * n * 1000000000, answer = End;
    while (Start <= End)
    {
        long long Mid = (Start + End) / 2;
        long long count = 0;
        for (int time : times)
        {
            count += Mid / time;
        }
        
        if (count >= n)
        {
            answer = Mid;
            End = Mid - 1;
        }
        else
        {
            Start = Mid + 1;
        }
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 1000000000000000000, Start = 1, End = 1000000000000000000;
    while (Start <= End)
    {
        long long Mid = (Start + End) / 2;
        long long cnt = 0;
        for (int t : times)
        {
            cnt += Mid / t;
        }
        if (cnt >= n)
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
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    int Start = 1, End = distance, answer = 0;
    while (Start <= End)
    {
        int Count = 0, Mid = (Start + End) / 2;
        int Last = 0;
        for (int rock : rocks)
        {
            if (rock - Last >= Mid)
            {
                Last = rock;
            }
            else
            {
                Count++;
            }
        }
        if (distance - Last < Mid)
        {
            Count++;
        }
        
        if (Count <= n)
        {
            answer = max(answer, Mid);
            Start = Mid + 1;
        }
        else
        {
            End = Mid - 1;
        }
    }
    
    return answer;
}
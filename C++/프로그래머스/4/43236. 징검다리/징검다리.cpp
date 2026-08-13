#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    
    int Start = 1, End = distance, answer = 1;
    while (Start <= End)
    {
        int Mid = (Start + End) / 2;
        int Del = 0, LastRock = 0;
        for (int r : rocks)
        {
            if (r - LastRock >= Mid)
            {
                LastRock = r;
            }
            else
            {
                Del++;
            }
        }
        if (distance - LastRock < Mid)
        {
            Del++;
        }
        
        if (Del <= n)
        {
            answer = Mid;
            Start = Mid + 1;
        }
        else
        {
            End = Mid - 1;
        }
    }
    return answer;
}
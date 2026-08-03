#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    int Start = 1, End = distance, answer = 0;
    while (Start <= End)
    {
        int Mid = (Start + End) / 2;
        int Last = 0, count = 0;
        for (int r : rocks)
        {
            if (r - Last >= Mid)
            {
                Last = r;
            }
            else
            {
                count++;
            }
        }
        if (distance - Last < Mid)
        {
            count++;
        }
        
        if (count <= n)
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
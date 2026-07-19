#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    int start = 1, end = distance, answer = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int rock = 0, LastRock = 0;
        for (int i = 0; i < rocks.size(); i++)
        {
            if (rocks[i] - LastRock < mid)
            {
                rock++;
            }          
            else
            {
                LastRock = rocks[i];
            }
        }
        if (distance - LastRock < mid)
        {
            rock++;
        }
        
        if (rock <= n)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return answer;
}
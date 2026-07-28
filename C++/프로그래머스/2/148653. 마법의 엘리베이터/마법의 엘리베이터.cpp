#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while (storey)
    {
        int r = storey % 10;
        if (r > 5)
        {
            answer += 10 - r;
            storey /= 10;
            storey++;
        }
        else if (r < 5)
        {
            answer += r;
            storey /= 10;
        }
        else
        {
            int forward = storey % 100 / 10;
            if (forward >= 5)
            {
                answer += 10 - r;
                storey /= 10;
                storey ++;
            }
            else
            {
                answer += r;
                storey /= 10;
            }
        }
    }
    
    return answer;
}
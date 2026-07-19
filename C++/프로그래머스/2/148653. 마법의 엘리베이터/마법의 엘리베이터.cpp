#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while (storey)
    {
        int Curr = storey % 10;
        if (Curr < 5)
        {
            answer += Curr;
            storey /= 10;
        }
        else if (Curr > 5)
        {
            answer += 10 - Curr;
            storey /= 10;
            storey++;
        }
        else
        {
            int Front = storey % 100 / 10;
            if (Front < 5)
            {
                answer += Curr;
                storey /= 10;
            }
            else
            {
                answer += 10 - Curr;
                storey /= 10;
                storey++;
            }
        }
    }
    return answer;
}

    
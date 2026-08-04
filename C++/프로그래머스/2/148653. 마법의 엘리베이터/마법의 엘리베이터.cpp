#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while (storey)
    {
        int Last = storey % 10;
        if (Last < 5)
        {
            answer += Last;
        }
        else if (Last > 5)
        {
            answer += 10 - Last;
            storey += 10 - Last;
        }
        else
        {
            answer += 5;
            if (storey / 10 % 10 >= 5)
            {
                storey += 5; 
            }
        }
        storey /= 10;
    }
    return answer;
}
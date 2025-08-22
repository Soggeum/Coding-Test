#include <string>
#include <vector>
#include <cmath>

using namespace std;

int division_count(int num)
{
    int result{ 0 };
    int i = 1;
    for (; i < sqrt(num); i++)
    {
        if (!(num % i))
            result += 2;
    }

    if (i * i == num)
        result++;

    return (result & 1) ? -num : num;
}


int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++)
        answer += division_count(i);
    
    return answer;
}
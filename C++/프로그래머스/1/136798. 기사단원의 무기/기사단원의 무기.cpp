#include <string>
#include <vector>
#include <cmath>

using namespace std;

int quotient(int num)
{
    int divisor = 0, i;
    for (i = 1; i < sqrt(num); i++) {
        if (!(num % i))
            divisor += 2;
    }
    if (num == i * i)
        divisor++;
    
    return divisor;
}

int solution(int number, int limit, int power) {
    int answer = 0, new_power;
    for (int i = 1; i <= number; i++) {
        new_power = quotient(i);
        answer += ( (new_power > limit)? power: new_power);
    }
    return answer;
}
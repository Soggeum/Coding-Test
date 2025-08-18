#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0, exp{};

    while (n) {
        answer += (n - (n / 10) * 10);
        n /= 10;
    }

    return answer;
}
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;
    while (n)
    {
        n = n & (n - 1);
        answer++;
    }
    
    return answer;
}
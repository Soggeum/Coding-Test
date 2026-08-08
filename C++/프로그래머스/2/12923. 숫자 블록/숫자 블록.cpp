#include <string>
#include <vector>

using namespace std;

// 2부터 루트까지 하면서 몫이 천만 이하면 리턴. 아니면 나눈 숫자를 나중에 리턴

int GetNum(long long n)
{
    int res = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i <= 10000000)
            {
                return n / i;
            }
            res = i;
        }
    }
    return res;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (long long i = begin; i <= end; i++)
    {
        answer.push_back(GetNum(i));
    }
    if (begin == 1)
    {
        answer[0] = 0;
    }
    return answer;
}
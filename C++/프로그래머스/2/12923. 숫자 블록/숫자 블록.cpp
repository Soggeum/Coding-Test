#include <string>
#include <vector>

using namespace std;

int Get(long long x)
{
    if (x == 1)
    {
        return 0;
    }
    
    int res = 1;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (x / i <= 10000000)
            {
                return x / i;
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
        answer.push_back(Get(i));
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1, 1);
    for (long long i = begin; i <= end; i++)
    {
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                long long n = i / j;
                if (n <= 10000000)
                {
                    answer[i - begin] = n;
                    break;
                }
                else
                {
                    answer[i - begin] = j;
                }
            }
        }
    }
    if (begin == 1)
    {
        answer[0] = 0;
    }
    return answer;
}
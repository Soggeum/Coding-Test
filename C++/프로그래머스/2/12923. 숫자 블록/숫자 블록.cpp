#include <string>
#include <vector>

using namespace std;

int FindBlock(int num)
{
    if (num == 1)
    {
        return 0;
    }
    
    int res = 1;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            int div = num / i;
            if (div <= 10000000)
            {
                return div;
            }
            else
            {
                res = i;
            }
        }
    }
    return res;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1);
    for (int num = begin; num <= end; num++)
    {
        int Block = FindBlock(num);
        answer[num - begin] = Block;
    }
    
    return answer;
}
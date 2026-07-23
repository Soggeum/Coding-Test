#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (int i = begin; i <= end; i++)
    {
        int num = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                if  (i / j > 10000000)
                {
                    num = j;
                }
                else
                {
                    num = i / j;
                    break;
                }
                
            }
        }
        answer.push_back(num);
    }
    
    if (begin == 1)
    {
        answer[0] = 0;
    }
    return answer;
}
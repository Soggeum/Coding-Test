#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, static_cast<int>(sequence.size()) - 1};
    int Start = 0, End = 0, sum = 0;
    while (End <= sequence.size())
    {
        if (sum < k)
        {
            if (End == sequence.size())
            {
                break;
            }
            sum += sequence[End++];
        }
        else if (sum == k)
        {
            if (End - Start - 1 < answer[1] - answer[0])
            {
                answer = {Start, End - 1};
            }
            sum -= sequence[Start++];
        }
        else
        {
            sum -= sequence[Start++];            
        }
    }
    return answer;
}
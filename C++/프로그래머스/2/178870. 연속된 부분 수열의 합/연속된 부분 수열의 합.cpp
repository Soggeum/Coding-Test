#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, static_cast<int>(sequence.size() - 1)};
    int Start = 0, End = 0, Sum = 0;
    while (Start <= End && End <= sequence.size())
    {
        if (Sum < k)
        {
            if (End == sequence.size())
            {
                break;
            }
            Sum += sequence[End++];
        }
        else if (Sum > k)
        {
            Sum -= sequence[Start++];
        }
        else
        {
            if (End - 1 - Start < answer[1] - answer[0])
            {
                answer[0] = Start;
                answer[1] = End - 1;
            }
            Sum -= sequence[Start++];
        }
    }
    return answer;
}
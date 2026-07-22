#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> stones, int k) {
    int Start = 0, End = k, answer = 200000000;
    multiset<int> ms;
    for (int i = Start; i < End; i++)
    {
        ms.insert(stones[i]);
    }
    while (End <= stones.size())
    {
        answer = min(answer, *ms.rbegin());
        if (End == stones.size())
        {
            break;
        }
        ms.insert(stones[End++]);
        auto it = ms.find(stones[Start++]);
        ms.erase(it);
    }
    return answer;
}
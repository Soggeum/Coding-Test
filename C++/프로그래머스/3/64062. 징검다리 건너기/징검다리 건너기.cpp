#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> stones, int k) {
    multiset<int> ms;
    int Start = 0, End = k;
    for (int i = Start; i < End; i++)
    {
        ms.insert(stones[i]);
    }
    
    int answer = *ms.rbegin();
    while (End <= stones.size())
    {
        const auto& it = ms.find(stones[Start++]);
        ms.erase(it);
        if (End == stones.size())
        {
            break;
        }
        ms.insert(stones[End++]);
        
        answer = min(answer, *ms.rbegin());
    }
    return answer;
}
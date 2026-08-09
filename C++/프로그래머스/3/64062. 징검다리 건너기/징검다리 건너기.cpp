#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 200000000;
    multiset<int> ms;
    int Start = 0, End = k;
    for (int i = Start ; i < End; i++)
    {
        ms.insert(stones[i]);
    }
    
    while (End <= stones.size())
    {
        int Max = *ms.rbegin();
        answer = min(answer, Max);
        auto it = ms.find(stones[Start++]);
        ms.erase(it);
        if (End == stones.size())
        {
            break;
        }
        ms.insert(stones[End++]);
    }
    return answer;
}
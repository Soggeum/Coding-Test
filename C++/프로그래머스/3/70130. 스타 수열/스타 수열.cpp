#include <string>
#include <vector>

using namespace std;

int solution(std::vector<int> a) {
    vector<int> LastUsed(a.size(), -1);
    vector<int> Count(a.size());
    
    for (int i = 0; i < a.size(); i++)
    {
        int n = a[i];
        if (LastUsed[n] != i - 1)
        {
            Count[n] += 2;
            LastUsed[n] = i;
        }
        else if (i + 1 < a.size() && a[i + 1] != n)
        {
            Count[n] += 2;
            LastUsed[n] = i + 1;
        }
        else
        {
            LastUsed[n] = i;
        }
    }
    
    int answer = 0;
    for (int i = 0; i < Count.size(); i++)
    {
        answer = max(answer, Count[i]);
    }
    return answer;
}
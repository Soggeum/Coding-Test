#include <string>
#include <vector>

using namespace std;

int solution(std::vector<int> a) {
    vector<int> LastIdx(a.size() , -1);
    vector<int> Num(a.size());
    
    for (int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        if (i - 1 != LastIdx[num] && a[i - 1] != num)
        {
            Num[num] += 2;
            LastIdx[num] = i;
        }
        else if (i + 1 < a.size() && a[i + 1] != num)
        {
            Num[num] += 2;
            LastIdx[num] = i + 1;
        }
    }
    
    int answer = 0;
    for (int n : Num)
    {
        answer = max(answer, n);
    }
    return answer;
}